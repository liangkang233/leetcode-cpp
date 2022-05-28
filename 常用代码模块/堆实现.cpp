// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
using namespace std;

// 堆排序
// 父节点: i,   子节点: 2i+1 2i+2
// 子节点: i,   父节点: (i-1)/2
// 对一个节点做heapify的时候，必须保证它的所有子树都已经是堆。  
void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
void max_heapify(int arr[], int start, int end) {
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len) {
    int i;
    // 初始化建堆，i從最後一個父節點開始調整
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先將第一個元素和已排好元素前一位做交換，再重新調整，直到排序完畢
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}


// 自实现大根堆 make_heap 
void maxHeapify(vector<int>& a, int i, int heapSize) {
    int l = i * 2 + 1, r = i * 2 + 2, largest = i; //完全二叉树 左右子节点
    if (l < heapSize && a[l] > a[largest]) {
        largest = l;
    } 
    if (r < heapSize && a[r] > a[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        maxHeapify(a, largest, heapSize);
    }
}
void buildMaxHeap(vector<int>& a, int heapSize) { // 生成堆
    for (int i = heapSize / 2; i >= 0; --i) {
        maxHeapify(a, i, heapSize);
    } 
}
void my_push_heap(vector<int>& a, int i) { // 最后一个元素下标i是新加入的
    while (i > 1) {
        int fa = (i-1)/2;
        if (a[i] <= a[fa])
            break;
        //如果子小于父就要不断向上交换下去
        swap(a[i], a[fa]);
        i = fa;
    }
}
void my_pop_heap(vector<int>& a, int& heapSize) { // 需要删除堆头 即为a[0]的值
    swap(a[0], a[heapSize]);
    heapSize--;
    maxHeapify(a, 0, heapSize);
}

// !!! 注意重载 make_heap 运算符时 与 priority_queue 不同 传入的是函数指针或实例的类 而非重载了 () 的类的类型名
// 并且之后的 pop_heap push_heap 都需要 传入该运算函数

// 使用 make_heap 的实例
int main () {
    int myints[] = {10,20,30,5,15};
    std::vector<int> v(myints,myints+5);

    std::make_heap (v.begin(),v.end());
    std::cout << "initial max heap   : " << v.front() << '\n';

    for (unsigned i=0; i<v.size(); i++)
        std::cout << v[i] << ' ' ;
    std::cout << '\n';

    std::pop_heap (v.begin(),v.end()); v.pop_back(); // 注意是先pop_heap 会把删除的元素放在容器尾 再pop_back
    std::cout << "max heap after pop : " << v.front() << '\n';

    v.push_back(99); std::push_heap (v.begin(),v.end());
    std::cout << "max heap after push: " << v.front() << '\n';

    std::sort_heap (v.begin(),v.end());

    std::cout << "final sorted range :";
    for (unsigned i=0; i<v.size(); i++)
        std::cout << ' ' << v[i];
    std::cout << '\n';

  return 0;
}