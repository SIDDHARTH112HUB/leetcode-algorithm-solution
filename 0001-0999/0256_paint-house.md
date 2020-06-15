[256.paint-house](https://leetcode.com/problems/paint-house/)  

There are a row of _n_ houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a `_n_ x _3_` cost matrix. For example, `costs[0][0]` is the cost of painting house 0 with color red; `costs[1][2]` is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

**Note:**  
All costs are positive integers.

**Example:**

**Input:** \[\[17,2,17\],\[16,16,5\],\[14,3,19\]\]
**Output:** 10
**Explanation:** Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. 
             Minimum cost: 2 + 5 + 3 = 10.  



**Solution:**  

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
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
      