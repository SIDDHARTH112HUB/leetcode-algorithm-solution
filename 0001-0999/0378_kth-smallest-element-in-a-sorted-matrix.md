[378.kth-smallest-element-in-a-sorted-matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)  

Given a _n_ x _n_ matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

**Example:**

  
matrix = \[
  
   \[ 1,  5,  9\],
  
   \[10, 11, 13\],
  
   \[12, 13, 15\]
  
\],
  
k = 8,
  

  
return 13.
  

**Note:**  
You may assume k is always valid, 1 ≤ k ≤ n2.  



**Solution:**  

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left = matrix[0][0], right = matrix.back().back();
        while( left < right ){
            int mid = left + ( right - left ) / 2;
            int cnt = 0;
            for( auto &vec:matrix){
                cnt += upper_bound(vec.begin(), vec.end(), mid) - vec.begin();
            }
            if( cnt < k ) left = mid+1;
            else right = mid;
        }
        return left;
    }
};
```
      