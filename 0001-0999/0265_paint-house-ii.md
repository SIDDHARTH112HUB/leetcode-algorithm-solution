[265.paint-house-ii](https://leetcode.com/problems/paint-house-ii/)  

There are a row of _n_ houses, each house can be painted with one of the _k_ colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a `_n_ x _k_` cost matrix. For example, `costs[0][0]` is the cost of painting house 0 with color 0; `costs[1][2]` is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

**Note:**  
All costs are positive integers.

**Example:**

**Input:** \[\[1,5,3\],\[2,9,4\]\]
**Output:** 5
**Explanation:** Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 

**Follow up:**  
Could you solve it in _O_(_nk_) runtime?  



**Solution:**  

```cpp
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int houseSize = costs.size();
        if(houseSize == 0) return 0;
        int colSize = costs[0].size();
        if(colSize == 0) return 0;
        vector<vector<int> > dp(houseSize, vector<int>(colSize, INT_MAX));
        for(int i = 0; i < houseSize; ++i){
            for(int j = 0; j < colSize; ++j) {
                if(i == 0) {
                    dp[i][j] = costs[i][j];
                    continue;
                }
                for(int k = 0; k < colSize; ++k) {
                    if(k == j) continue;
                    dp[i][k] = min(dp[i][k], dp[i-1][j] + costs[i][k]);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
```
      