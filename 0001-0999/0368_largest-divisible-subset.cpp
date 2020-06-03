//Link: https://leetcode.com/problems/largest-divisible-subset/ 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        if( size == 0 )return {};
        vector<int> parent(size, -1);
        vector<int> dp(size, 1);
        vector<int> ret;
        sort(nums.begin(), nums.end());
        for( int i = 0; i<size; i++){
            for( int j=0; j<i; j++){
                if( nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1 ){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if( dp[i] > dp[ans])
                ans = i;
        }
        
        while( ans != -1){
            ret.push_back(nums[ans]);
            ans = parent[ans];
        }
        return ret;
    }
};