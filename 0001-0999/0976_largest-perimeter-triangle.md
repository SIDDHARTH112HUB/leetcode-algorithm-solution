[976.largest-perimeter-triangle](https://leetcode.com/problems/largest-perimeter-triangle/)  

Given an array `A` of positive lengths, return the largest perimeter of a triangle with **non-zero area**, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return `0`.

**Example 1:**

**Input:** \[2,1,2\]
**Output:** 5

**Example 2:**

**Input:** \[1,2,1\]
**Output:** 0

**Example 3:**

**Input:** \[3,2,3,4\]
**Output:** 10

**Example 4:**

**Input:** \[3,6,2,3\]
**Output:** 8

**Note:**

1.  `3 <= A.length <= 10000`
2.  `1 <= A[i] <= 10^6`  



**Solution:**  

```cpp
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int ans = 0;
        for( int i = A.size()-1; i >=2; i--){
            int a  = A[i];
            for( int j = i - 1; j >=1; j--){
                int b = A[j];
                
                if( a >= 2*b)
                    continue;
                for( int k = j-1; k >= 0; k--){
                    int c = A[k];
                    if( b + c <= a)
                        break;
                    if( b+c > a && a-b < c && a - c < b)
                        return a+b+c;
                    while( k > 0 && c == A[k-1])
                        k--;
                }
                while( b == A[j-1])
                    j--;
            }
            while( a == A[i-1])
                i--;
        }
        return ans;
    }
};
```
      