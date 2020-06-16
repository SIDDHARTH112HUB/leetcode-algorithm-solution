[1230.toss-strange-coins](https://leetcode.com/problems/toss-strange-coins/)  

You have some coins.  The `i`\-th coin has a probability `prob[i]` of facing heads when tossed.

Return the probability that the number of coins facing heads equals `target` if you toss every coin exactly once.

**Example 1:**

**Input:** prob = \[0.4\], target = 1  
**Output:** 0.40000  

**Example 2:**

**Input:** prob = \[0.5,0.5,0.5,0.5,0.5\], target = 0  
**Output:** 0.03125  

**Constraints:**

*   `1 <= prob.length <= 1000`
*   `0 <= prob[i] <= 1`
*   `0 <= target` `<= prob.length`
*   Answers will be accepted as correct if they are within `10^-5` of the correct answer.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, double> > m;
    double probabilityOfHeads(vector<double>& prob, int target){
        vector<double> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i <= prob.size(); ++i)
            for(int j = min(target, i); j >=0; --j)
                dp[j] = (j > 0 ? dp[j-1] : 0) * prob[i-1] + dp[j] * (1.0-prob[i-1]);
        return dp[target];
    }
    double probabilityOfHeads1(vector<double>& prob, int target, int idx = 0) {
        if(target == 0) {
            double p = 1.0;
            for(int i = idx; i < prob.size(); ++i) {
                p *= (1 - prob[i]);
            }
            return p;
        }
        
        if(idx >= prob.size()) return 0;
        if(m[idx].count(target) ) return m[idx][target];
        double p = 0;
        p += probabilityOfHeads1(prob, target, idx + 1) * (1- prob[idx] );
        p += probabilityOfHeads1(prob, target - 1, idx + 1) * prob[idx];
        m[idx][target] = p;
        return p;
    }
};
```
      