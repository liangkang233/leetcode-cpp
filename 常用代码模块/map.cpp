// http://www.cplusplus.com/reference/map/map/key_comp/
// http://www.cplusplus.com/reference/map/map/value_comp/

// map 的 key_cmp 与 value_cmp 区别
// key_cmp 是直接采用实例的map定义的key比较函数，
// value_cmp value 是指的 map的元素即 pair 对象，比较的是两个 pair的key 所以两个函数差不多

#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

int main ()
{
    std::map<char,int> mymap;
    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    // map重载 与 优先队列一样
    // struct MyCmp {
    //     bool operator()(string l, string r) const { return strcasecmp(l.c_str(), r.c_str()) < 0; }
    // };
    // map<string, int, MyCmp> mymap;

    // map::value_comp
    auto value_cmp = mymap.value_comp();
    std::cout << "mymap contains:\n";
    std::pair<char,int> highest = *mymap.rbegin();          // last element
    std::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( value_cmp(*it++, highest) );

  return 0;
}

int main () 
{
    std::map<char,int> mymap;
    // std::map<char,int, greater<int>> mymap; // map set 的自定义比较函数 传函数 而不是类
    mymap['x']=1001;
    mymap['y']=2002;
    mymap['z']=3003;

    // map::key_comp
    auto key_cmp = mymap.key_comp();
    std::cout << "mymap contains:\n";
    char highest = mymap.rbegin()->first;     // key value of last element
    std::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( key_cmp((*it++).first, highest) );
    std::cout << '\n';
}

// map  unordered_map set 基础用法
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

