[646.maximum-length-of-pair-chain](https://leetcode.com/problems/maximum-length-of-pair-chain/)  

You are given `n` pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair `(c, d)` can follow another pair `(a, b)` if and only if `b < c`. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

**Example 1:**  

  
**Input:** \[\[1,2\], \[2,3\], \[3,4\]\]
  
**Output:** 2
  
**Explanation:** The longest chain is \[1,2\] -> \[3,4\]
  

**Note:**  

1.  The number of given pairs will be in the range \[1, 1000\].  



**Solution:**  

```cpp
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
```
      