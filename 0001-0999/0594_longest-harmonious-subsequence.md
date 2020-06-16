[594.longest-harmonious-subsequence](https://leetcode.com/problems/longest-harmonious-subsequence/)  

We define a harmounious array as an array where the difference between its maximum value and its minimum value is **exactly** 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible [subsequences](https://en.wikipedia.org/wiki/Subsequence).

**Example 1:**

  
**Input:** \[1,3,2,2,5,2,3,7\]  
**Output:** 5  
**Explanation:** The longest harmonious subsequence is \[3,2,2,2,3\].  

**Note:** The length of the input array will not exceed 20,000.  



**Solution:**  

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto n : nums) ++cnt[n];
        int ans = 0;
        for(auto n :nums) {
            int cnt1 = cnt[n-1];
            int cnt2 = cnt[n+1];
            if(cnt1 > 0)
                ans = max(ans, cnt1 + cnt[n]);
            if(cnt2 > 0)
                ans = max(ans, cnt2 + cnt[n]);
        }
        return ans;
    }
};
```
      