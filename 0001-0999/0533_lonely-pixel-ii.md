[533.lonely-pixel-ii](https://leetcode.com/problems/lonely-pixel-ii/)  

Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row **R** and column **C** that align with all the following rules:

1.  Row R and column C both contain exactly N black pixels.
2.  For all rows that have a black pixel at column C, they should be exactly the same as row R

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

**Example:**  

  
**Input:**                                            
  
\[\['W', 'B', 'W', 'B', 'B', 'W'\],    
  
 \['W', 'B', 'W', 'B', 'B', 'W'\],    
  
 \['W', 'B', 'W', 'B', 'B', 'W'\],    
  
 \['W', 'W', 'B', 'W', 'B', 'W'\]\] 
  

  
N = 3
  
**Output:** 6
  
**Explanation:** All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
  
        0    1    2    3    4    5         column index                                            
  
0    \[\['W', **'B'**, 'W', **'B'**, 'B', 'W'\],    
  
1     \['W', **'B'**, 'W', **'B'**, 'B', 'W'\],    
  
2     \['W', **'B'**, 'W', **'B'**, 'B', 'W'\],    
  
3     \['W', 'W', 'B', 'W', 'B', 'W'\]\]    
  
row index
  

  
Take 'B' at row R = 0 and column C = 1 as an example:
  
Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
  
Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.
  

  

**Note:**  

1.  The range of width and height of the input 2D array is \[1,200\].  



**Solution:**  

```cpp
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size(), n = picture[0].size();
        vector<int> row(m), col(n);
        vector<string> rowStr(m);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                rowStr[i] += picture[i][j];
                if(picture[i][j] == 'B') {
                    ++row[i];
                    ++col[j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            if(row[i] == N) {
                for(int j = 0; j < n; ++j) {
                    bool f = true;
                    if(col[j] == N && picture[i][j] == 'B') {
                        for(int k = 0; k < m; ++k) {
                            if(picture[k][j] == 'B' && rowStr[i] != rowStr[k]){
                                f = false;
                                break;
                            }
                        }
                        ans += f;
                    }
                    
                }
            }
        }
        return ans;
    }
};
```
      