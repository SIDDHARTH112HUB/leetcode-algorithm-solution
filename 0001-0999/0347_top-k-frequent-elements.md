[347.top-k-frequent-elements](https://leetcode.com/problems/top-k-frequent-elements/)  

Given a non-empty array of integers, return the **_k_** most frequent elements.

**Example 1:**

**Input:** nums = \[1,1,1,2,2,3\], k = 2
**Output:** \[1,2\]

**Example 2:**

**Input:** nums = \[1\], k = 1
**Output:** \[1\]

**Note:**

*   You may assume _k_ is always valid, 1 ≤ _k_ ≤ number of unique elements.
*   Your algorithm's time complexity **must be** better than O(_n_ log _n_), where _n_ is the array's size.
*   It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
*   You can return the answer in any order.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int> > pq;
        for(auto n : nums)
            ++m[n];
        for(auto &it : m)
            pq.push({it.second, it.first});
        vector<int> ans;
        while(k-- >0 && pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
```
      