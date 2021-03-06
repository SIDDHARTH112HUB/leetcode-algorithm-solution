[531.lonely-pixel-i](https://leetcode.com/problems/lonely-pixel-i/)  

Given a picture consisting of black and white pixels, find the number of **black** lonely pixels.

The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

**Example:**  

  
**Input:** 
  
\[\['W', 'W', 'B'\],
  
 \['W', 'B', 'W'\],
  
 \['B', 'W', 'W'\]\]
  

  
**Output:** 3
  
**Explanation:** All the three 'B's are black lonely pixels.
  

**Note:**  

1.  The range of width and height of the input 2D array is \[1,500\].  



**Solution:**  

```cpp
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
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
            for(int j = 0; j < n; ++j) {
                if(picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
```
      