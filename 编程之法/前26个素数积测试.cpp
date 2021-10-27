#include<iostream>
using namespace std;


int SuNumber( int i) 
{
    for (int j = 2; j < i; j++) {
        if(i % j == 0)
            return -1;
    }
    return i;
}     


int main()
{
    // int a, b, temp = 0;
    // char SuMap[10001] = {0}; //是否素数  
    // int SuNum[10000] = {0}; //所有素数集合
    // cin >> a >> b;

    // for (int i = 2; i <= b; i++) {
    //     int k = SuNumber(i) ;
    //     if( k > 0) {
    //         SuNum[temp] = k;
    //         SuMap[i] = 1;
    //         temp++;
    //     }
    // }

    int j = 0; 
    int a[26] = {0};
    for(int i =2; j<26; i++) {
        int k = SuNumber(i);
        if(k > 0) {
            a[j++] = k;
            cout << k << ' ';
        }
    }
    cout << endl;
    j = 1;
    for (int i = 0; a[i] != 0; i++) {
        cout << a[i] << ' ';
        j *= a[i];
    }
    cout << endl << j ;

    return 0;
}
    