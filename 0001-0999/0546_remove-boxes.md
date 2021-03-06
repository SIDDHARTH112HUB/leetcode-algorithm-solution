[546.remove-boxes](https://leetcode.com/problems/remove-boxes/)  

Given several boxes with different colors represented by different positive numbers.  
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get `k*k` points.  
Find the maximum points you can get.

**Example 1:**

  
**Input:** boxes = \[1,3,2,2,2,3,4,3,1\]  
**Output:** 23  
**Explanation:**  
\[1, 3, 2, 2, 2, 3, 4, 3, 1\]   
----> \[1, 3, 3, 4, 3, 1\] (3\*3=9 points)   
----> \[1, 3, 3, 3, 1\] (1\*1=1 points)   
----> \[1, 1\] (3\*3=9 points)   
----> \[\] (2\*2=4 points)  

**Constraints:**

*   `1 <= boxes.length <= 100`
*   `1 <= boxes[i] <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    
    int removeBoxes(vector<int>& boxes) {
        if(boxes.size() == 0) return 0;
        int dp[100][100][100];
        memset(dp, 0, sizeof(dp));
        return dfs(boxes, 0, boxes.size()-1, 0, dp);
    }
    
    int dfs(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
        if(i > j) return 0;
        if(dp[i][j][k]) return dp[i][j][k];
        int res = (1+k) * (1+k) + dfs(boxes, i+1, j, 0, dp);
        for(int m = i+1; m <=j; ++m) {
            if(boxes[i] == boxes[m]) {
                res = max(res, dfs(boxes, i+1, m-1, 0, dp) + dfs(boxes, m, j, k+1, dp));
            }
        }
        dp[i][j][k] = res;
        return res;
    }
};
```
      