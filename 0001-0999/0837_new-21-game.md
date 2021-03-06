[837.new-21-game](https://leetcode.com/problems/new-21-game/)  

Alice plays the following game, loosely based on the card game "21".

Alice starts with `0` points, and draws numbers while she has less than `K` points.  During each draw, she gains an integer number of points randomly from the range `[1, W]`, where `W` is an integer.  Each draw is independent and the outcomes have equal probabilities.

Alice stops drawing numbers when she gets `K` or more points.  What is the probability that she has `N` or less points?

**Example 1:**

  
**Input:** N = 10, K = 1, W = 10
  
**Output:** 1.00000
  
**Explanation: ** Alice gets a single card, then stops.
  

**Example 2:**

  
**Input:** N = 6, K = 1, W = 10
  
**Output:** 0.60000
  
**Explanation: ** Alice gets a single card, then stops.
  
In 6 out of W = 10 possibilities, she is at or below N = 6 points.
  

**Example 3:**

  
**Input:** N = 21, K = 17, W = 10
  
**Output:** 0.73278

**Note:**

1.  `0 <= K <= N <= 10000`
2.  `1 <= W <= 10000`
3.  Answers will be accepted as correct if they are within `10^-5` of the correct answer.
4.  The judging time limit has been reduced for this question.  



**Solution:**  

```cpp
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
```
      