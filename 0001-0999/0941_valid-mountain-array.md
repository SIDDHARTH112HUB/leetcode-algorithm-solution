[941.valid-mountain-array](https://leetcode.com/problems/valid-mountain-array/)  

Given an array `A` of integers, return `true` if and only if it is a _valid mountain array_.

Recall that A is a mountain array if and only if:

*   `A.length >= 3`
*   There exists some `i` with `0 < i < A.length - 1` such that:
    *   `A[0] < A[1] < ... A[i-1] < A[i]`
    *   `A[i] > A[i+1] > ... > A[A.length - 1]`

  
![](https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png)

**Example 1:**

  
**Input:** \[2,1\]
  
**Output:** false
  

**Example 2:**

  
**Input:** \[3,5,5\]
  
**Output:** false
  

**Example 3:**

  
**Input:** \[0,3,2,1\]
  
**Output:** true

**Note:**

1.  `0 <= A.length <= 10000`
2.  `0 <= A[i] <= 10000`  



**Solution:**  

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if( A.size() <= 2) return false;
        int idx = max_element(A.begin(), A.end()) - A.begin();
        if( idx == 0 || idx == A.size() -1 ) return false;
        int l = idx, r = idx;
        while( l > 0 || r <A.size()-1 ){
            if( l > 0 && A[l-1] >= A[l]  )
                return false;
            l--;
            if( r < A.size()- 1 && A[r+1]>=A[r] )
                return false;
            r++;
        }
        return true;
    }
};
```
      