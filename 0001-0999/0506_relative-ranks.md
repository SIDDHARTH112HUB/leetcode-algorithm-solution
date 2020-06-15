[506.relative-ranks](https://leetcode.com/problems/relative-ranks/)  

Given scores of **N** athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

**Example 1:**  

**Input:** \[5, 4, 3, 2, 1\]
**Output:** \["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"\]
**Explanation:** The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal".   
For the left two athletes, you just need to output their relative ranks according to their scores.

**Note:**  

1.  N is a positive integer and won't exceed 10,000.
2.  All the scores of athletes are guaranteed to be unique.  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i)
            m[nums[i]] = i;
        vector<string> ans(nums.size());
        int idx = 0;
        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        for(auto it = m.rbegin(); it != m.rend(); ++it) {
            int i = it->second;
            ans[i] = idx >= rank.size() ? to_string(idx+1):rank[idx];
            ++idx;
        }
        return ans;
    }
};
```
      