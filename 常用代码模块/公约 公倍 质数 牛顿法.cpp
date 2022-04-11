#include <iostream>
#include <vector>
using namespace std;

int MinBei(int a, int b) {	
    // 求最大公约数 迭代写法
    int tmp, count = a * b;
    while (b) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    // cout << "yue: " << a;
    return count / a ;
    //两数相乘等于 最大公约数乘最小公倍数
}

// 求最大公约数的递归写法
int gcd (int a, int b) {
    return b ? gcd(b, a%b) : a;
}



// 最原始
bool isPrime(int n){
    if (n <= 3) {
        return n > 1;
    }
    for(int i = 2; i < n; i++){
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// 初步优化  
// 若不是质数 其一定存在因数p1<=sqrt(n)，p2>=sqrt(n)
bool isPrime1(int n) {
    if (n <= 3) {
        return n > 1;
    }
    int s = (int)sqrt(n);
    for (int i = 2; i <= s; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

// 质数还有一个特点，就是它总是等于 6x-1 或者 6x-5，其中 x 是大于等于1的自然数。
bool isPrime2(int num) {
    if (num <= 3) {
        return num > 1;
    }
    // 不在6的倍数两侧的一定不是质数
    if (num % 6 != 1 && num % 6 != 5) {
        return false;
    }
    int s = (int)sqrt(num);
    // 若这个数是合数，则有质因数i,i <= sqrt(num)
    // 且i为质数一定为6倍数两侧，以6为步长寻找
    for (int i = 6; i <= s; i += 6) {
        if (num % (i-1) == 0 || num % (i+1) == 0) {
            return false;
        }
    }
    return true;
}

// 求 [1,n) 范围内质数个数 可以采用此方法
// https://leetcode-cn.com/problems/count-primes/ 
// [埃拉托色尼筛选法](https://baike.baidu.com/item/%E5%9F%83%E6%8B%89%E6%89%98%E8%89%B2%E5%B0%BC%E7%AD%9B%E9%80%89%E6%B3%95/4524938)
// 其原理也十分易懂:从1到n遍历，假设当前遍历到m,则把所有小于n的、且是m的倍数的整数标为和数;
// 遍历完成后，没有被标为和数的数字即为质数。

int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> prime(n, true) ;
    int count = n - 2; //去掉不是质数的1 和范围外的n
    for(int i = 2; i < n; ++i){
        if (prime[i]) {
            for (int j = 2*i; j < n; j += i){ // 将i的整数倍删除
                if (prime[j]) {
                    prime[j] = false;
                    --count;
                }
            }
        }
    }
    return count;
}

// 优化版本
int countPrimes1(int n) {
    if (n <= 2) return 0;
    vector<bool> prime(n, true);
    int i = 3, sqrtn = sqrt(n), count = n / 2;  // i>=3的偶数一定不是质数
    for (int i = 3; i <= sqrtn; i+=2) {
        if(prime[i]) { 
        // 只对当前是未被标记的质数才进行 平方后累加2i的数设定为合数 减少重复遍历 
        // i为3开始的奇数 进入合数统计时 +i必定为偶数数没必要遍历 已经提前把偶数个数减少了
            for (int j = i*i; j < n; j += 2*i){
            // j不断 + 2i 为了避免偶数 的遍历
                if (prime[j]) {
                    --count ;
                    prime[j] = false;
                }
            }
        }
    }
    return count;
}


// 牛顿法平方根
int main()
{
    double x1, x2;
    float a;
    scanf("%f", &a);
    x2 = 1.0;
    do 
    {
        x1 = x2;
        x2 = (x1 + a / x1) / 2;
        // x2 -= (x2 + a / x2) / 2; 也可如此简写
    } while (fabs(x1-x2)>pow(10,-5));
    // } while (fabs(x1-x2) > 1e-5);
    printf("value:%lf", x2);
    system("pause");
    return 0;
}
// 当求A的平方根时 设f(x) = x^2
// 上问题即为求 f(x) = A的解
// 构造函数 F(X) = f(x) - A = x^2 - A
// A为所求的常数 用牛顿法求解不断迭代下去 直到 Xn+1 与 Xn 差值足够小
// 即迭代求 Xn+1 = Xn - F(Xn) / F'(Xn)