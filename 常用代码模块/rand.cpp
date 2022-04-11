/* rand是一个产生随机数的函数，但严格意义上来说它产生的是伪随机数，
因为计算机的随机数都是伪随机数，即是由小M多项式序列生成的，
其中产生每个小序列都有一个初始值，即随机种子（小M多项式序列的周期是65535，
即每次利用一个随机种子生成的随机数的周期是65535，当你取得65535个随机数后它们又重复出现，
即以相同的随机种子重新开始一个周期） 。所以它不是真真意义上的随机数，是一个伪随机数，
是根据一个数（我们可以称它为种子）为基准以某个递推公式推算出来的一系列数，
当这系列数很大的时候，就符合正态公布，从而相当于产生了随机数，但这不是真正的随机数，
当计算机正常开机后，这个种子的值是定了的，除非你破坏了系统。
此时搭配srand函数使用， srand用来设置rand()产生随机数时的随机数种子，
通常可以利用time(0)的返回值或NULL来当做参数。如果每次seed都设相同值，
rand()所产生的随机数值每次就会一样。 */



// 简言之，srand 修改rand的种子值 改变生成不同的伪随机数列
#include <iostream>  
#include <ctime>   
// #include <cstdlib>

#include <random>
using namespace std;  

#define MIN 1    //随机数产生的范围      
#define MAX 10  

int main() {   
    int i;   
    // c 不使用这句话 下面每次调用这个文件 rand 生成的数列是一样的
    srand((unsigned int)time(0));    
    for(i=0; i<10; i++) { //产生随机数  
        cout<<MIN + (int)MAX * rand() / (RAND_MAX + 1)<<"\t";   
        // cout<< rand() << endl;
    }  
    cout << endl;

    // cpp 使用random
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(MIN, MAX);

    for (int n = 0; n < 10; ++n) {
        cout << distr(eng) << "; ";
    }
    cout << endl;

    return   0;     
}   

