#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;


//c11 for range 迭代
std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
for (auto n :vec) {
    std::cout << n;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    
    // 成员函数的声明
    int something(int io);           // 普通类方法
    TreeNode(int x, TreeNode *left); // 类的构造函数
};

// 上述成员函数的类外定义
int TreeNode::something(int io) {return io;};
TreeNode::TreeNode(int x, TreeNode *left):val(x), left(left), right(nullptr) {};


// 优先队列 小根堆使用方法：  （队列默认采用的是 less 大根堆，sort 默认是 less 从小到大）下面展示三种重载排序的方法
    // 题目378  "重载>"，用默认的great
    class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            struct point {
                int val, x, y;
                point(int val, int x, int y) : val(val), x(x), y(y) {}
                bool operator > (const point& a) const { return this->val > a.val; }
            };
            priority_queue<point, vector<point>, greater<point>> que;
            // 第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象  与sort刚好相反
            int n = matrix.size();
            for (int i = 0; i < n; i++) {
                que.emplace(matrix[i][0], i, 0);
            }
            for (int i = 0; i < k - 1; i++) {
                point now = que.top();
                que.pop();
                if (now.y != n - 1) {
                    que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
                }
            }
            return que.top().val;
        }
    };
    // 题目23  "重载类的<"，用默认的less（所以省略了该参数）
    // 注意重载函数放在类内 默认会有this 下面这个两个参数的>重载一定要放类外 否则报错
    struct Status {
        int val;
        ListNode *ptr;
        // 类内重载
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };
    // 算术 相等 比较 通常应该为非成员函数 即类外重载
    bool operator > (const Status &lhs, const Status &rhs) {
        return lhs.val > rhs.val;
    }

    class Solution {
    public:
        priority_queue <Status> q;
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            for (auto node: lists) {
                if (node) q.push({node->val, node});
            }
            ListNode head, *tail = &head;
            while (!q.empty()) {
                auto f = q.top(); q.pop();
                tail->next = f.ptr; 
                tail = tail->next;
                if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
            }
            return head.next;
        }
    };
    
    // 题目 https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/you-xian-dui-lie-yi-tian-chu-yi-ge-xuan-pkcim/
    // "重载()" 其实greater和less就是一个模板调用的模板类，里面重载了元素的() 返回> 或<的bool
    // 内置类型运算符 无法重载 pair是一个模板类 所以可以重载pair运算符
    bool operator() (const mypair& L, const mypair& R) {
        return L.first + L.second > R.first + R.second;
    }

    // 最后一种方法 直接构造优先队列需要的 比较类 类似原greater
    struct com{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        }
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,com> q;


    // list用法: http://c.biancheng.net/view/6892.html
    

    // multiset set 自定义元素比较规则 与 队列一样 传入重载了()的比较类
    #include <set>
    struct rule{
        bool operator()(pair<int,int>&a, pair<int,int>&b){
            return a.second + a.first > b.second + b.first;
        }
    };
    set<pair<int, int>, rule> myset;

    // 或者重载元素的比较运算符
    multiset<Status, greater<Status>>

