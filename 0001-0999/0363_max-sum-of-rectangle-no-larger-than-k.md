[363.max-sum-of-rectangle-no-larger-than-k](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)  

Given a non-empty 2D matrix _matrix_ and an integer _k_, find the max sum of a rectangle in the _matrix_ such that its sum is no larger than _k_.

**Example:**

**Input:** matrix = \[\[1,0,1\],\[0,-2,3\]\], k = 2
**Output:** 2 
**Explanation:** Because the sum of rectangle `[[0, 1], [-2, 3]]` is 2,
             and 2 is the max number no larger than k (k = 2).

**Note:**

1.  The rectangle inside the matrix must have an area > 0.
2.  What if the number of rows is much larger than the number of columns?  



**Solution:**  

```cpp
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool revert = false;
        if (n > m) {
            swap(n, m);
            revert = true;
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            vector<int> sum(m);
            for(int j = i; j < n; ++j) {
                for(int k = 0; k < m; ++k) {
                    if(revert)
                        sum[k] += matrix[j][k];
                    else
                        sum[k] += matrix[k][j];
                }
                set<int> s;
                s.insert(0);
                int cur = 0;
                for(int num : sum) {
                    cur += num;
                    auto it = s.lower_bound(cur - K);
                    if(it != s.end()) ans = max(ans, cur - *it);
                    s.insert(cur);
                }
            }
        }
        return ans;
    }
};
```
      