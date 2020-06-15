[349.intersection-of-two-arrays](https://leetcode.com/problems/intersection-of-two-arrays/)  

Given two arrays, write a function to compute their intersection.

**Example 1:**

**Input:** nums1 = \[1,2,2,1\], nums2 = \[2,2\]
**Output:** \[2\]

**Example 2:**

**Input:** nums1 = \[4,9,5\], nums2 = \[9,4,9,8,4\]
**Output:** \[9,4\]

**Note:**

*   Each element in the result must be unique.
*   The result can be in any order.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> ans;
        for(auto n : nums2) {
            if(s1.count(n))ans.insert(n);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};
```
      