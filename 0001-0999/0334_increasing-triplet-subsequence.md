[334.increasing-triplet-subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/)  

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

> Return true if there exists _i, j, k_  
> such that _arr\[i\]_ < _arr\[j\]_ < _arr\[k\]_ given 0 ≤ _i_ < _j_ < _k_ ≤ _n_\-1 else return false.

**Note:** Your algorithm should run in O(_n_) time complexity and O(_1_) space complexity.

**Example 1:**

  
**Input:** \[1,2,3,4,5\]
  
**Output:** true
  

**Example 2:**

  
**Input:** \[5,4,3,2,1\]
  
**Output:** false  



**Solution:**  

```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MAX;
        for(auto n : nums) {
            if(n > mx)
                return true;
            if(n > mn) 
                mx = min(mx, n);
            else
                mn = n;
        }
        return false;
    }
};
```
      