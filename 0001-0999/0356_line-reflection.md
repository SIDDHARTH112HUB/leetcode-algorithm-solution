[356.line-reflection](https://leetcode.com/problems/line-reflection/)  

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points symmetrically, in other words, answer whether or not if there exists a line that after reflecting all points over the given line the set of the original points is the same that the reflected ones.

Note that there can be repeated points.

**Follow up:**  
Could you do better than O(_n_2) ?

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/04/23/356_example_1.PNG)

  
**Input:** points = \[\[1,1\],\[-1,1\]\]  
**Output:** true  
**Explanation:** We can choose the line x = 0.  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/04/23/356_example_2.PNG)

  
**Input:** points = \[\[1,1\],\[-1,-1\]\]  
**Output:** false  
**Explanation:** We can't choose a line.  

**Constraints:**

*   `n == points.length`
*   `1 <= n <= 10^4`
*   `-10^8 <= points[i][j] <= 10^8`  



**Solution:**  

```cpp
class Solution {
public:
    bool isReflected(vector<vector<int>>& _points) {
        set<vector<int> > dup;
        vector<vector<int> > points;
        for(auto &p : _points) {
            if(dup.count(p) == 0) {
                points.push_back(p);
                dup.insert(p);
            }
        }
        sort(points.begin(), points.end());
        sort(points.begin() + points.size() / 2, points.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int line = (points[0][0] + points.back()[0]);
        for(int i = 0; i <= points.size() / 2; ++i) {
            int j = points.size() - i - 1;
            if(points[i][1] == points[j][1] || points[i][0] == points[j][0]) {
                if(points[i][0] + points[j][0] != line)
                    return false;
            }else
                return false;
        }
        return true;
    }
};
```
      