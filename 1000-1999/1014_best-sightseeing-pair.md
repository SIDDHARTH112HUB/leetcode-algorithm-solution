[1014.best-sightseeing-pair](https://leetcode.com/problems/best-sightseeing-pair/)  

Given an array `A` of positive integers, `A[i]` represents the value of the `i`\-th sightseeing spot, and two sightseeing spots `i` and `j` have distance `j - i` between them.

The _score_ of a pair (`i < j`) of sightseeing spots is (`A[i] + A[j] + i - j)` : the sum of the values of the sightseeing spots, **minus** the distance between them.

Return the maximum score of a pair of sightseeing spots.

**Example 1:**

  
**Input:** \[8,1,5,2,6\]
  
**Output:** 11
  
**Explanation:** i = 0, j = 2, `A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11`
  

**Note:**

1.  `2 <= A.length <= 50000`
2.  `1 <= A[i] <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = INT_MIN, mx = A[0];
        for( int i = 1; i < A.size(); i++ ){
            ans = max(ans, A[i]-i + mx);
            mx = max(A[i]+i, mx);
        }
        return ans;
    }
};
```
      