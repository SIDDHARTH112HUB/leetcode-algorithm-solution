//Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/ 
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, INT_MAX);
        //dp[0] = 0;
        for(int i = 0; i < ranges.size(); ++i) {
            int l = max(i - ranges[i], 0);
            int r = min(i + ranges[i], n);
            if(l == r) continue;
            for(int j = l; j <= r; ++j) {
                if(dp[l] == INT_MAX) dp[l] = 0;
                dp[j] = min(dp[j], (l >= 0 ? dp[l] : 0) + 1);
            }
        }
        int ans = 0;
        for(auto i : dp) {
            if(i == INT_MAX) return -1;
            ans = max(ans, i);
        }
        return ans;
    }
    
    
};