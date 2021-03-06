[1402.reducing-dishes](https://leetcode.com/problems/reducing-dishes/)  

A chef has collected data on the `satisfaction` level of his `n` dishes. Chef can cook any dish in 1 unit of time.

_Like-time coefficient_ of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  `time[i]`\*`satisfaction[i]`

Return the maximum sum of _Like-time coefficient_ that the chef can obtain after dishes preparation.

Dishes can be prepared in **any** order and the chef can discard some dishes to get this maximum value.

**Example 1:**

  
**Input:** satisfaction = \[-1,-8,0,5,-9\]
  
**Output:** 14
  
**Explanation:** After Removing the second and last dish, the maximum total _Like-time coefficient_ will be equal to (-1\*1 + 0\*2 + 5\*3 = 14). Each dish is prepared in one unit of time.

**Example 2:**

  
**Input:** satisfaction = \[4,3,2\]
  
**Output:** 20
  
**Explanation:** Dishes can be prepared in any order, (2\*1 + 3\*2 + 4\*3 = 20)
  

**Example 3:**

  
**Input:** satisfaction = \[-1,-4,-5\]
  
**Output:** 0
  
**Explanation:** People don't like the dishes. No dish is prepared.
  

**Example 4:**

  
**Input:** satisfaction = \[-2,5,-1,0,3,-3\]
  
**Output:** 35
  

**Constraints:**

*   `n == satisfaction.length`
*   `1 <= n <= 500`
*   `-10^3 <= satisfaction[i] <= 10^3`  



**Solution:**  

```cpp
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int idx = 1;
        int sum = 0;
        int ans = 0;
        for(int n : satisfaction) {
            if(n >= 0) {
                sum += n;
                ans += n * idx;
                ++idx;
            }
        }
        
        vector<int> arr;
        idx = 1;
        vector<int > dp(satisfaction.size() + 1, INT_MIN);
        dp[0] = 0;
        for(int n : satisfaction) {
            if(n < 0) {
                for(int cnt = idx - 1; cnt>=0; --cnt)
                    dp[cnt+1] = max(dp[cnt+1], dp[cnt] + n * (cnt+1) + sum);
                ++idx;
                
            }
        }
        int mx = 0, mi = 0;
        for(int i = 0; i < dp.size(); ++i) {
            if(dp[i] > mx) {
                mx = dp[i];
            }
        }
        //cout<<mx<<endl;
        return ans + mx;
    }
};
```
      