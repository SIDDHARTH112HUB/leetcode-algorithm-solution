//Link: https://leetcode.com/problems/maximum-length-of-pair-chain/ 
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        pair<int, int> dp[n];
        dp[0] = {1, pairs[0][1]};
        for(int i = 1; i < n; ++i) {
            auto &p = pairs[i];
            if(p[0] > dp[i-1].second){
                dp[i] = {dp[i-1].first + 1, p[1]};
            }else
                dp[i] = {dp[i-1].first, min(p[1], dp[i-1].second)};
        }
        return dp[n-1].first;
    }
};