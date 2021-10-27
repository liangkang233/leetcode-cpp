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

// 容器拷贝示例

void test () {
  int myints[]={10,20,30,40,50,60,70};
  std::vector<int> myvector (7);

  std::copy ( myints, myints+7, myvector.begin() );
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
// Output:
// myvector contains: 10 20 30 40 50 60 70


//  容器常用打印方法,下面string替换为打印容器元素类型
    std::ostream_iterator<string> os(cout, " ");
    std::copy(vi.begin(), vi.end(), os);
    // 或者直接代局部
    std::copy(vi.begin(), vi.end(), std::ostream_iterator<int>(std::cout, " "));


 // 容器排序（默认升序）
    std::sort(v.begin(), v.end());
    // 逆序排序
    std::sort(v.rbegin(), v.rend());
    // 或者
    std::sort(v.begin(), v.end(), std::greater<type>());


 // 递归迭代容器内值使用for_each
    for(vector<int>::iterator itor = v.begin();itor!=v.end();++itor) {
        cout<<*itor<<endl;
    }   //原写法

    void fun(int i ) {
        cout<<i<<endl;
    }
    int main() {
        int a[] = { 1, 2, 3, 4};
        vector<int> v(a, a+sizeof(a)/sizeof(int));
        for_each(v.begin(), v.end(), fun);
    }


/* 队列queue和stack的基本用法
    queue 先进先出，常用于dfs 如算最大流、青蛙跳杯子
    stack 后进先出，调用函数基本一样
    引申到deque（双向队列）和list（链表）

    #include <queue>
    queue<node> myqueue;
    // 成员函数 empty front back push pop(删首) emplace(使用构造函数插入) swap(交换queue)

    #include <stacck> 
    stack<node> mystack;
*/

int main ()
{
    int i;
    unordered_map<int, string> a;
    map<int, string> b;
    set<string> c;
    // map常用插入方法,
    a.insert( {1, "i"} );
    a.insert(make_pair(2, "io"));
    a.insert(pair<int, string>(3, "iop"));
    a.insert(unordered_map<int, string>::value_type(3, "iop"));

    // insert插入重复索引不会覆盖什么也不执行。insert返回一个pair。
    // 该pair的fist成员为一个指向插入元素或阻止插入的元素的迭代器
    // second成员为bool表示是否插入成功。
    // b.insert_or_assign //插入时发现有重复的会替换掉，
    // []方式也是可以覆盖的。
    auto test = a.insert(make_pair(1, "nihao"));
    auto test = a.insert({1, "nihao"});
    // cout << typeid(test.first).name() << endl;
    cout << test.first->first << endl;
    cout << test.first->second << endl;
    cout << test.second << endl;

    // 同理，set的insert返回值 类似map，返回一个pair 
    // first为要插入元素的set的迭代器，second为插入成功的bool
    auto ans = c.insert("io"); 


    // 使用 []等方法查元素时，看需求 可能有必要使用前查其key是否存在。 不存在的key使用[]访问后会初始化为类型默认值
    // 由于std对map的++重载过，所以可以直接如此用
    // unordered_map<char, int> mp;   mp[ch]++; 不存在的map会直接初始化为0并+1

    // map的迭代方式
    for (auto &[ch, num] : mp) {
            buckets[num].push_back(ch);
    }

    // 判断 map set 元素是否存在
    // 法一：使用 count()
    unordered_set<char> broken; 
    return broken.count('a');
    // 法二：使用find()
    unordered_map<int, string>::iterator it_a = a.find(1);
    if ( it_a != a.end()) {
        cout << it_a->first << endl;
        cout << it_a->second << endl;
    }
    else
        cout << "未找到数据" << endl;

    return 0;
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


//c11 for range 迭代
std::vector<int> vec {1,2,3,4,5,6,7,8,9,10};
for (auto n :vec) {
    std::cout << n;
}

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
    