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
// copy只负责拷贝元素，不负责开辟空间，源容器空间不足复制会报错
// 追加容器一般用 insert

//用法1:在指定位置it前“插入”值为val的元素,返回指向这个元素的迭代器,
iterator insert( iterator it, const TYPE &val ); 
//用法2:在指定位置it前“插入”num个值为val的元素 
void insert( iterator it, size_type num, const TYPE &val ); 
//用法3:在指定位置it前“插入”区间[start, end)的所有元素. 
void insert( iterator it, input_iterator start, input_iterator end ); 

// 使用back_inserter
copy(v2.begin(),v2.end(),back_inserter(v1));
move(v2.begin(),v2.end(),back_inserter(v1));
// 切记move右值引用后并不代表该指向资源被释放，使用该元素的行为未定义 最好手动释放
// 例如 一般对于stack的引用移动pop会写成：x = move(_q.front()); q.pop();这样


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
    queue 先进先出，常用于bfs 如算最大流、青蛙跳杯子
    stack 后进先出，调用函数基本一样
    引申到deque（双向队列）和list（链表）

    #include <queue>
    queue<node> myqueue;
    // 成员函数 empty front back push pop(删首) emplace(使用构造函数插入) swap(交换queue)

    #include <stacck> 
    stack<node> mystack;
*/