[221.maximal-square](https://leetcode.com/problems/maximal-square/)  

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

**Example:**

  
**Input:** 
  
1 0 1 0 0
  
1 0 1 1 1
  
1 1 1 1 1
  
1 0 0 1 0
  

  
**Output:** 4  



**Solution:**  

```cpp
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        int dp[m+1][n+1] = {0};
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1'){
                    dp[i+1][j+1] = min(min(dp[i+1][j], dp[i][j+1]), dp[i][j]) + 1;
                    ans = max(ans, dp[i+1][j+1]);
                }
            }
        }
        return ans * ans;
    }
    int maximalSquare1(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if( m == 0 ) return 0;
        int n = matrix[0].size();
        if( n == 0 ) return 0;
        vector<int> h(n+1);
        h[n] = -1;
        int ans = 0;
        for( int i = 0; i<m; i++){
            for( int j = 0; j<n; j++){
                if( matrix[i][j] == '1'){
                    h[j]++;
                }else{
                    h[j]=0;
                }
            }
            ans = max(ans, maxHistogram(h));
        }
        return ans;
    }
    
    int maxHistogram(vector<int> &h){
        int ans = 0;
        stack<pair<int, int> > stk;
        for( int i = 0; i<h.size(); i++){
            while( stk.size() && stk.top().first > h[i]){
                int prev_h = stk.top().first;
                stk.pop();    
                int prev_idx = 0;
                if( stk.size() )
                    prev_idx = stk.top().second+1;
                int minH = min(prev_h, i - prev_idx);
                ans = max( minH * minH, ans);
            }
            stk.push({h[i], i});
        }
        return ans;
    }
};
```
      