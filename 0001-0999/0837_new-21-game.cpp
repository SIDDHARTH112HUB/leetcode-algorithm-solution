//Link: https://leetcode.com/problems/new-21-game/ 
class Solution {
public:
    //P[i] = 1/W * sum[i-1]
    //sum[i] = sum[i-1] + P[i] = sum[i-1] + sum[i-1] / W     (when i <= W)
    
    //P[i] = 1/W * (sum[i-1] - sum[i-W-1])
    //m[i] = sum[i-1] + P[i] = sum[i-1] + (sum[i-1] - sum[i-W-1]) / W     (when i > W)
    
    //P[i] = 1/W * sum[K-1]     (when i > K && i <= W)
    //sum[i] = 1/W * (sum[K-1] - sum[i-W-1])    (when i > K && i > W)
    double new21Game(int N, int K, int W) {
        if(N - K >= W || K==0) return 1;
        if(N == 0) return K == 0;
        vector<double> dp(K+W);
        dp[0] = 1.0;
        for(int i =1; i < K+W; ++i) {
            dp[i] = dp[i-1];
            if(i <= W) dp[i] += dp[i-1] / W;
            else {
                //0....W......i, we get W~i rate.  * 1/W
                dp[i] += (dp[i-1] - dp[i - W - 1])/W;
            }
            if(i > K){
                //0....W...K.....i, we get W~K rate.  * 1/W
                dp[i] -= (dp[i-1] - dp[K-1]) /W;
            }
        }
        return dp[N] - dp[K-1];
    }
};