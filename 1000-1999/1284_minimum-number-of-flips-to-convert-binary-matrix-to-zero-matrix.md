[1284.minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix](https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/)  

Given a `m x n` binary matrix `mat`. In one step, you can choose one cell and flip it and all the four neighbours of it if they exist (Flip is changing 1 to 0 and 0 to 1). A pair of cells are called neighboors if they share one edge.

Return the _minimum number of steps_ required to convert `mat` to a zero matrix or **\-1** if you cannot.

Binary matrix is a matrix with all cells equal to 0 or 1 only.

Zero matrix is a matrix with all cells equal to 0.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/11/28/matrix.png)

  
**Input:** mat = \[\[0,0\],\[0,1\]\]  
**Output:** 3  
**Explanation:** One possible solution is to flip (1, 0) then (0, 1) and finally (1, 1) as shown.  

**Example 2:**

  
**Input:** mat = \[\[0\]\]  
**Output:** 0  
**Explanation:** Given matrix is a zero matrix. We don't need to change it.  

**Example 3:**

  
**Input:** mat = \[\[1,1,1\],\[1,0,1\],\[0,0,0\]\]  
**Output:** 6  

**Example 4:**

  
**Input:** mat = \[\[1,0,0\],\[1,0,0\]\]  
**Output:** -1  
**Explanation:** Given matrix can't be a zero matrix  

**Constraints:**

*   `m == mat.length`
*   `n == mat[0].length`
*   `1 <= m <= 3`
*   `1 <= n <= 3`
*   `mat[i][j]` is 0 or 1.  



**Solution:**  

```cpp
class Solution {
public:
    int hash(vector<vector<int>>& mat) {
        int n = 0;
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0;j < mat[i].size(); ++j){
                n |= mat[i][j] << (i*mat.size()+j);
            }
        }
        return n;
    }
    int minFlips(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<vector<vector<int> > > q;
        set<int> v;
        q.push(mat);
        v.insert(hash(mat));
        int step = 0;
        int d[5] = {0, 1, 0, -1, 0};
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                auto mt = q.front();
                
                q.pop();
                
                if(hash(mt) == 0) return step;
                for(int i = 0; i < mat.size(); ++i) {
                    for(int j = 0; j < mat[i].size(); ++j) {
                        auto newm = mt;
                        newm[i][j] = !mt[i][j];
                        for(int k = 0; k < 4; ++k) {
                            int nx = i + d[k];
                            int ny = j + d[k + 1];
                            if(nx < 0 || ny < 0 || nx >= m || ny >= n )continue;
                            newm[nx][ny] = !newm[nx][ny];
                        }
                        int nh = hash(newm);
                        if(v.count(nh)) continue;
                        q.push(newm);
                        v.insert(nh);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};
```
      