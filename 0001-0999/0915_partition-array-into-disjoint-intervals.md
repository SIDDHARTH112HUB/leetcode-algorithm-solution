[915.partition-array-into-disjoint-intervals](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)  

Given an array `A`, partition it into two (contiguous) subarrays `left` and `right` so that:

*   Every element in `left` is less than or equal to every element in `right`.
*   `left` and `right` are non-empty.
*   `left` has the smallest possible size.

Return the **length** of `left` after such a partitioning.  It is guaranteed that such a partitioning exists.

**Example 1:**

**Input:** \[5,0,3,8,6\]
**Output:** 3
**Explanation:** left = \[5,0,3\], right = \[8,6\]

**Example 2:**

**Input:** \[1,1,1,0,6,12\]
**Output:** 4
**Explanation:** left = \[1,1,1,0\], right = \[6,12\]

**Note:**

1.  `2 <= A.length <= 30000`
2.  `0 <= A[i] <= 10^6`
3.  It is guaranteed there is at least one way to partition `A` as described.  



**Solution:**  

```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int l = 1;
        int maxLeft = A[0];
        for( int i =1; i<A.size(); i++){
            if( maxLeft <= A[i] ){
                int tmp = maxLeft;
                while(i < A.size() && maxLeft <= A[i] ){
                    tmp = max( tmp, A[i]);
                    i++;
                }
                maxLeft = tmp;
                if( i == A.size() )
                    return l;
                l = i+1;
            }else{
                l = i+1;
            }
        }
        return l;
    }
};
```
      