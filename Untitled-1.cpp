#include <iostream>
#include <vector>
using namespace std;

int main () {
    vector<int> nums{1,2,3};
    int n = 3, k = 1;
    nums.insert(nums.begin(), nums.begin()+(n-k), nums.end());
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    
    return 0;
}