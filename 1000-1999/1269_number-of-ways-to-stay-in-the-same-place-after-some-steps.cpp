//Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/ 
class Solution {
public:
    int M = 1e9 + 7;
    int numWays(int steps, int arrLen) {
        map<int, int> dp;
        dp[0] = 1;
        for(int i = 0; i <steps; ++i) {
            auto t = dp;
            dp = {};
            for(auto it : t) {
                int idx = it.first;
                int count = it.second;
                if(idx - 1 >= 0) {
                    dp[idx - 1] += t[idx];
                    dp[idx - 1] %= M;
                }
                if(idx + 1 < arrLen){
                    dp[idx+ 1] += t[idx];
                    dp[idx+ 1] %= M;
                }
                dp[idx] += t[idx];
                dp[idx] %= M;
            }
        }
        return dp[0];
    }
};