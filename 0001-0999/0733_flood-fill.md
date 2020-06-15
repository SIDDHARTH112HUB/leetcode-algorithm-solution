[733.flood-fill](https://leetcode.com/problems/flood-fill/)  

An `image` is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate `(sr, sc)` representing the starting pixel (row and column) of the flood fill, and a pixel value `newColor`, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

**Example 1:**  

**Input:** 
image = \[\[1,1,1\],\[1,1,0\],\[1,0,1\]\]
sr = 1, sc = 1, newColor = 2
**Output:** \[\[2,2,2\],\[2,2,0\],\[2,0,1\]\]
**Explanation:** 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.

**Note:**

*   The length of `image` and `image[0]` will be in the range `[1, 50]`.
*   The given starting pixel will satisfy `0 <= sr < image.length` and `0 <= sc < image[0].length`.
*   The value of each color in `image[i][j]` and `newColor` will be an integer in `[0, 65535]`.  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        stack<pair<int, int> > stk;
        stk.push({sr,sc});
        int maxRow = image.size();
        int maxCol = image[0].size();
        int realNewCol = newColor;
        newColor = -1;
        while(!stk.empty()){
            auto item = stk.top();
            stk.pop();
            image[item.first][item.second] = newColor;
            if( item.first - 1 >=0 ){
                if( image[item.first - 1 ][item.second] == oldColor ){
                    image[item.first-1][item.second] = newColor;
                    stk.push({item.first-1, item.second});
                }
            }
            if( item.first + 1 < maxRow ){
                if( image[item.first + 1 ][item.second] == oldColor ){
                    image[item.first+1][item.second] = newColor;
                    stk.push({item.first+1, item.second});
                }
            }
            if( item.second + 1 < maxCol ){
                if( image[item.first ][item.second+1] == oldColor ){
                    image[item.first][item.second + 1] = newColor;
                    stk.push({item.first, item.second+1});
                }
            }
            if( item.second - 1 >=0 ){
                if( image[item.first ][item.second-1] == oldColor ){
                    image[item.first][item.second - 1] = newColor;
                    stk.push({item.first, item.second-1});
                }
            }
        }
        for( auto &item: image){
            for(auto &i : item){
                if( i == - 1)
                    i = realNewCol;
            }
        }
        return image;
    }
};
```
      