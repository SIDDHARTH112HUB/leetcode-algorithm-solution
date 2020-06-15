[845.longest-mountain-in-array](https://leetcode.com/problems/longest-mountain-in-array/)  

Let's call any (contiguous) subarray B (of A) a _mountain_ if the following properties hold:

*   `B.length >= 3`
*   There exists some `0 < i < B.length - 1` such that `B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]`

(Note that B could be any subarray of A, including the entire array A.)

Given an array `A` of integers, return the length of the longest _mountain_. 

Return `0` if there is no mountain.

**Example 1:**

**Input:** \[2,1,4,7,3,2,5\]
**Output:** 5
**Explanation:** The largest mountain is \[1,4,7,3,2\] which has length 5.

**Example 2:**

**Input:** \[2,2,2\]
**Output:** 0
**Explanation:** There is no mountain.

**Note:**

1.  `0 <= A.length <= 10000`
2.  `0 <= A[i] <= 10000`

**Follow up:**

*   Can you solve it using only one pass?
*   Can you solve it in `O(1)` space?  



**Solution:**  

```cpp
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if( A.size() <= 2 ) return 0;
        A.push_back( A.back() );
        int i = 0, b = 0, ans = 0;
        while(i < A.size() - 1 ){
            
            while( i < A.size()-1 && A[i] >= A[i+1])i++;
            b = i;
            
            while( i < A.size()-1 && A[i] < A[i+1])i++;
            int summit = i;
            while( i < A.size()-1 && A[i] > A[i+1])i++;
            if( summit == i )
                continue;
            ans = max(i - b + 1, ans);
        }
        return ans;
    }
};
```
      