[661.image-smoother](https://leetcode.com/problems/image-smoother/)  

Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

**Example 1:**  

  
**Input:**
  
\[\[1,1,1\],
  
 \[1,0,1\],
  
 \[1,1,1\]\]
  
**Output:**
  
\[\[0, 0, 0\],
  
 \[0, 0, 0\],
  
 \[0, 0, 0\]\]
  
**Explanation:**
  
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
  
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
  
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
  

**Note:**  

1.  The value in the given matrix is in the range of \[0, 255\].
2.  The length and width of the given matrix are in the range of \[1, 150\].  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int n = M.size();
        if( n == 0 ) return {};
        int m = M[0].size();
        if( m == 0 ) return {};
        vector<vector<int> > ans(n, vector<int>(m));
        int dx[8] = {0,0,1,-1,1,1,-1,-1};
        int dy[8] = {1,-1,0,0,1,-1,1,-1};
        for( int i = 0; i< n; i++){
            for( int j = 0; j < m; j++){
                int sum = M[i][j];
                int cnt = 1;
                for( int k = 0; k<8; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if( nx < 0 || ny < 0 || nx >=n || ny >= m) continue;
                    sum += M[nx][ny];
                    ++cnt;
                }
                ans[i][j] = sum/cnt;
            }
        }
        return ans;
    }
};
```
      