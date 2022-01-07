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
    
    // 仅声明未定义
    int something(int io) {};           // 普通类方法
    TreeNode(int x, TreeNode *left) {}; //类的构造函数
};

// 上述类内声明的外定义
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
    //题目23  "重载<"，用默认的less（所以省略了该参数）
    class Solution {
    public:
        struct Status {
            int val;
            ListNode *ptr;
            bool operator < (const Status &rhs) const {
                return val > rhs.val;
            }
        };
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
    // 此处数据类型为pair，不知道该怎么重载其greater所以就这样写了。
    struct com{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            return a.second>b.second;
        }
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,com> q;


    // list用法: http://c.biancheng.net/view/6892.html
    