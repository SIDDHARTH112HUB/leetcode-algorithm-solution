[835.image-overlap](https://leetcode.com/problems/image-overlap/)  

Two images `A` and `B` are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)

We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the _overlap_ of this translation is the number of positions that have a 1 in both images.

(Note also that a translation does **not** include any kind of rotation.)

What is the largest possible overlap?

**Example 1:**

  
**Input:** A = \[\[1,1,0\],
  
            \[0,1,0\],
  
            \[0,1,0\]\]
  
       B = \[\[0,0,0\],
  
            \[0,1,1\],
  
            \[0,0,1\]\]
  
**Output:** 3
  
**Explanation:** We slide A to right by 1 unit and down by 1 unit.

**Notes:** 

1.  `1 <= A.length = A[0].length = B.length = B[0].length <= 30`
2.  `0 <= A[i][j], B[i][j] <= 1`  



**Solution:**  

```cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans = 0;
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < A[0].size(); ++j){
                ans = max(ans, helper(A, B, i, j));
                ans = max(ans, helper(B, A, i, j));
            }
        }
        return ans;
    }
    
    int helper(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y) {
        int sy = y, ans = 0;
        for(int i = 0; x < A.size(); ++i){
            y = sy;
            for(int j = 0; y < A[0].size(); ++j) {
                if(A[i][j] == B[x][y] && B[x][y] == 1)
                    ++ans;
                ++y;
            }
            ++x;
        }
        return ans;
    }
};
```
      