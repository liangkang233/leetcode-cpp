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
    // 该pair的fist成员为一个指向插入元素或阻止插入的元素的pair
    // first成员为指向元素的 下标 键值 迭代器
    // second成员为bool表示是否插入成功。
    // b.insert_or_assign //插入时发现有重复的会替换掉，
    // []方式也是可以覆盖的。
    auto test = a.insert(make_pair(1, "nihao"));
    auto test = a.insert({1, "nihao"}); //等价上式
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

