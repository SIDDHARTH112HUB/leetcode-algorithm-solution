//Link: https://leetcode.com/problems/combination-sum-iv/ 
class Solution {
public:
    
    map<int, int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        
        if( target < 0 || nums.size() == 0 ) return 0;
        if( target == 0 ) return 1;
        auto it = dp.find(target);
        if( it != dp.end() ) return it->second; 
        int cnt = 0;
        
        for( int n: nums){
            cnt += combinationSum4(nums, target - n);
        }
        dp[target] = cnt;
        return cnt;
    }
};