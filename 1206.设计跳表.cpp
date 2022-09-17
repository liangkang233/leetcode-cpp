/*
 * @lc app=leetcode.cn id=1206 lang=cpp
 *
 * [1206] 设计跳表
 */

#include <vector>
#include <iostream>
#include <random>
using namespace std;
// redis zset 跳表的实现

// @lc code=start
constexpr int MAX_LEVEL = 32; // 最多32层，索引31层
constexpr double P_FACTOR = 0.25;

struct SkiplistNode {
    int val;
    vector<SkiplistNode *> forward;
    // 每一个节点的forword元素为 当前层的右边节点(list 的 next)
    // 例如 forword[i] 即为 该列元素的第i层的右边节点指针
    SkiplistNode(int _val, int _maxLevel = MAX_LEVEL) : val(_val), forward(_maxLevel, nullptr) {}
};

class Skiplist {
private:
    SkiplistNode * head;
    int M_level; // 当前跳表 存在的最大层数
public:
    /* 随机生成 lv 个数, 按照平均的概率计算, 每4个生成1级索引, 16个生成2级索引, 64个生成3级索引 ....*/
    int randomLevel() {
        int lv = 1;
        while ((rand()%1000) / 10000  < P_FACTOR && lv < MAX_LEVEL) {
            lv++;
        }
        return lv;
    }

    Skiplist(): M_level(0) {
        head = new SkiplistNode(-1);
    }
    
    bool search(int target) {
        SkiplistNode *curr = this->head;
        for (int i = M_level - 1; i >= 0; i--) {
            /* 找到第 i 层小于且最接近 target 的元素*/
            while (curr->forward[i] && curr->forward[i]->val < target) {
                curr = curr->forward[i];
            }
        }
        curr = curr->forward[0];
        /* 检测当前元素的值是否等于 target */
        if (curr && curr->val == target) {
            return true;
        } 
        return false;
    }
    
    void add(int num) {
        vector<SkiplistNode *> update(MAX_LEVEL, head); // update 为需要插入元素的 左边一位  即 update 右侧 new->update 右侧 forword
        SkiplistNode *curr = this->head;
        for (int i = M_level - 1; i >= 0; i--) {
            /* 找到第 i 层小于且最接近 num 的元素*/
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        int lv = randomLevel();
        M_level = max(M_level, lv);
        SkiplistNode *newNode = new SkiplistNode(num, lv);
        for (int i = 0; i < lv; i++) {
            /* 对第 i 层的状态进行更新，将当前元素的 forward 指向新的节点 */
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
    
    bool erase(int num) {
        vector<SkiplistNode *> update(MAX_LEVEL, nullptr);
        SkiplistNode *curr = this->head;
        for (int i = M_level - 1; i >= 0; i--) {
            /* 找到第 i 层小于且最接近 num 的元素*/
            while (curr->forward[i] && curr->forward[i]->val < num) {
                curr = curr->forward[i];
            }
            update[i] = curr;
        }
        curr = curr->forward[0];
        /* 如果值不存在则返回 false */
        if (!curr || curr->val != num) {
            return false;
        }
        for (int i = 0; i < M_level; i++) {
            if (update[i]->forward[i] != curr) {
                break;
            }
            /* 对第 i 层的状态进行更新，将 forward 指向被删除节点的下一跳 */
            update[i]->forward[i] = curr->forward[i];
        }
        delete curr;
        /* 更新当前的 level */
        while (M_level > 1 && head->forward[M_level - 1] == nullptr) {
            M_level--;
        }
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
// @lc code=end