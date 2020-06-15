[350.intersection-of-two-arrays-ii](https://leetcode.com/problems/intersection-of-two-arrays-ii/)  

Given two arrays, write a function to compute their intersection.

**Example 1:**

**Input:** nums1 = \[1,2,2,1\], nums2 = \[2,2\]
**Output:** \[2,2\]

**Example 2:**

**Input:** nums1 = \[4,9,5\], nums2 = \[9,4,9,8,4\]
**Output:** \[4,9\]

**Note:**

*   Each element in the result should appear as many times as it shows in both arrays.
*   The result can be in any order.

**Follow up:**

*   What if the given array is already sorted? How would you optimize your algorithm?
*   What if _nums1_'s size is small compared to _nums2_'s size? Which algorithm is better?
*   What if elements of _nums2_ are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for( int n : nums1)
            ++m1[n];
        for( int n : nums2)
            ++m2[n];
        vector<int> ans;
        for( auto it : m1){
            if( m2.count(it.first)){
                int n = min(it.second, m2[it.first]);
                for( int i = 0; i< n; i++)
                    ans.push_back(it.first);
            }
        }
        return ans;
    }
};
```
      