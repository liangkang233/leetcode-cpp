#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, Y = 1000000007, maxn = 0;
    long long ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 0, temp = 0; i < n; i++) {
        if(s[i] == '1') {
            temp++;
            maxn = max(temp, maxn);
        }
        else 
            temp=0;
    }
    int last = -1;
    for(int i = 0, temp = 0; i < n; i++) {
        if(s[i] == '1') {
            temp++;
            if(temp == maxn) {
                int r = i, l = i - maxn+1;
                ans = (ans + (long long)(l - last) * (n - r)) % Y;
                last = l;
            }
        }
        else 
            temp=0;
    }
    cout << ans << endl;
    return 0;
}