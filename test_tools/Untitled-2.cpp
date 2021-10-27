// 测试  功能忘了

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void dfs(vector<int>& candidates, int target , vector<vector<int>> & ans , vector<int>res , int sum  , int start ){
        if(sum == target){
            ans.push_back(res);
            return ;
        }
        if(start >= candidates.size()){
            return ;
        }
        for(int i = start ; i < candidates.size() ; i ++ ){
            if(i != start && candidates[i] == candidates[i-1])continue;
            if(sum + candidates[i] <= target){
                res.push_back(candidates[i]);
                sum += candidates[i];
                dfs(candidates , target , ans , res , sum , i+1);
                res.pop_back();
                sum -= candidates[i];
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty() || target <= 0){
            return {};
        }
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans ;
        vector<int> res ; // 临时存储 
        // 第一个零 sum 统计加到多少了    第二个零是 start  开始位置 
        dfs(candidates , target , ans , res , 0, 0);
        return ans ; 
    }
};


int main(){
    Solution s ;
    vector<int> candidates = {7200,10600,8000,7300,2000,7200,16100,9600,21300,13600,7200,6800,400,700,29700,25300,12900,12100,7700};
    int tar = 108000;
    vector<vector<int>> ret = s.combinationSum2( candidates , tar );
    for(int i = 0 ; i < ret.size() ; i ++ ){
        for(int j = 0 ; j < ret[i].size() ; j ++ ){
            cout << ret[i][j] << "+" ;
            if(j == ret[i].size()-1){
                cout << ret[i][j] << "=" << 108000 ;
            }
        }
        cout << endl ; 
    }
}