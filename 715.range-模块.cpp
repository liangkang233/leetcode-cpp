#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

// 57题进阶
// 正确答案应该用线段树 超纲了。。。 用map的官解
class RangeModule {
private:
    map<int, int> mp;
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it != mp.begin()) {
            auto start = prev(it); // prev next 上一个 下一个 迭代器
            if (start->second >= right) {
                return;
            }
            if (start->second >= left) {
                left = start->first;
                mp.erase(start);
            }
        }
        while (it != mp.end() && it->first <= right) {
            right = max(right, it->second);
            it = mp.erase(it);
        }
        mp[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it == mp.begin()) {
            return false;
        }
        it = prev(it);
        return right <= it->second;
    }
    
    void removeRange(int left, int right) {
        auto it = mp.upper_bound(left);
        if (it != mp.begin()) {
            auto start = prev(it);
            if (start->second >= right) {  
                int ri = start->second;
                if (start->first == left) {
                    mp.erase(start);
                }
                else {
                    start->second = left;
                }
                if (right != ri) {
                    mp[right] = ri;
                }
                return;
            }
            else if (start->second > left) {
                start->second = left;
            }
        }
        while (it != mp.end() && it->first < right) {
            if (it->second <= right) {
                it = mp.erase(it);
            }
            else {
                mp[right] = it->second;
                mp.erase(it);
                break;
            }
        }
    }
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

// 珂朵莉树（Chtholly Tree）
// 大佬方案 https://blog.csdn.net/CC_dsm/article/details/98166835
class Chtholly {
    struct Node {
        unsigned l{}, r{};
        int data{};
        Node(unsigned l, unsigned r = 0, int data = 0) : l(l), r(r), data(data) {}
        bool operator<(const Node& rhs) const { return l < rhs.l; }
    };
public:
    set<Node> s;
    auto split(unsigned pos) { // split(pos)操作将包含位置pos的区间原始区间[l,r] 分裂成[l,pos-1]和[pos,r]，并返回后者迭代器。 区间最小为1
        auto it = s.lower_bound({ pos });
        if (it != s.end() && it->l == pos) return it;
        it--;
        int l = it->l, r = it->r, d = it->data;
        s.erase(it); // 删除原区间 裂开为两个区间
        s.emplace(l, pos - 1, d);
        return s.emplace(pos, r, d).first;
    }

    void assign(unsigned l, unsigned r, bool val = 0) {
        auto it = split(r + 1);
        s.erase(split(l), it); // l - r 小区间全部删除
        s.emplace(l, r, val); // 添加新指定区间 val 为 1 或 0
    }

    bool check(unsigned l, unsigned r) {
        auto it = split(r + 1); // 与assign 一样 一定要先切割出r+1区间以免 干扰判断 下面的就是错的
        // return all_of(split(l), split(r + 1), [](auto&& n) { return n.data; });
        return all_of(split(l), it, [](auto&& n) { return n.data; }); // 遍历 l到r 的迭代器 如果data出现false return fasle
    }
};

class RangeModule {
    Chtholly tree{ {{1,100000000}} }; // 1-100000000 原始区间data为0 都没用上 拥有的区间data为1
public:
    void addRange(int left, int right) { tree.assign(left, right - 1, 1); }
    bool queryRange(int left, int right) { return tree.check(left, right - 1); }
    void removeRange(int left, int right) { tree.assign(left, right - 1); }
};
