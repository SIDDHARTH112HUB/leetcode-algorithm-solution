[947.most-stones-removed-with-same-row-or-column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)  

On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

Now, a _move_ consists of removing a stone that shares a column or row with another stone on the grid.

What is the largest possible number of moves we can make?

**Example 1:**

  
**Input:** stones = \[\[0,0\],\[0,1\],\[1,0\],\[1,2\],\[2,1\],\[2,2\]\]
  
**Output:** 5
  

**Example 2:**

  
**Input:** stones = \[\[0,0\],\[0,2\],\[1,1\],\[2,0\],\[2,2\]\]
  
**Output:** 3
  

**Example 3:**

  
**Input:** stones = \[\[0,0\]\]
  
**Output:** 0
  

**Note:**

1.  `1 <= stones.length <= 1000`
2.  `0 <= stones[i][j] < 10000`  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, int > m;
    int islands = 0;
    int find(int x){
        if( m.count(x) == 0 ) m[x]=x, islands++;
        if( m[x] != x ) m[x] = find(m[x]);
        return m[x];
    }
    void uni(int x, int y){
        x = find(x);
        y = find(y);
        if( x != y ) m[x] = y, islands--;
    }
    int removeStones(vector<vector<int>>& stones) {
        for( auto &s: stones){
            uni(s[0], ~s[1]);
        }
        return stones.size() - islands;
    }
};
```
      