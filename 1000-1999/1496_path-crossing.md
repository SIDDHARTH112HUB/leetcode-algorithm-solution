[1496.path-crossing](https://leetcode.com/problems/path-crossing/)  

Given a string `path`, where `path[i] = 'N'`, `'S'`, `'E'` or `'W'`, each representing moving one unit north, south, east, or west, respectively. You start at the origin `(0, 0)` on a 2D plane and walk on the path specified by `path`.

Return `True` if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return `False` otherwise.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/06/10/screen-shot-2020-06-10-at-123929-pm.png)

  
**Input:** path = "NES"  
**Output:** false   
**Explanation:** Notice that the path doesn't cross any point more than once.  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/06/10/screen-shot-2020-06-10-at-123843-pm.png)

  
**Input:** path = "NESWW"  
**Output:** true  
**Explanation:** Notice that the path visits the origin twice.

**Constraints:**

*   `1 <= path.length <= 10^4`
*   `path` will only consist of characters in `{'N', 'S', 'E', 'W}`  



**Solution:**  

```cpp
class Solution {
public:
    bool isPathCrossing(string path) {
        map<int, set<int> >m;
        m[0].insert(0);
        int x = 0, y = 0;
        for(auto c :path) {
            if(c == 'N'){
                x -= 1;
            }else if(c == 'S'){
                x += 1;
            }else if(c == 'E'){
                y += 1;
            }else if(c == 'W'){
                y -= 1;
            }
            if(m[x].count(y)) return true;
            m[x].insert(y);
        }
        return false;
    }
};
```
      