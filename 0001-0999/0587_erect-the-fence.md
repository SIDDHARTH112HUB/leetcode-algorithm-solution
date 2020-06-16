[587.erect-the-fence](https://leetcode.com/problems/erect-the-fence/)  

There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the **minimum length** of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.

**Example 1:**

  
**Input:** \[\[1,1\],\[2,2\],\[2,0\],\[2,4\],\[3,3\],\[4,2\]\]
  
**Output:** \[\[1,1\],\[2,0\],\[4,2\],\[3,3\],\[2,4\]\]
  
**Explanation:**
  
![](https://assets.leetcode.com/uploads/2018/10/12/erect_the_fence_1.png)
  

**Example 2:**

  
**Input:** \[\[1,2\],\[2,2\],\[4,2\]\]
  
**Output:** \[\[1,2\],\[2,2\],\[4,2\]\]
  
**Explanation:**
  
![](https://assets.leetcode.com/uploads/2018/10/12/erect_the_fence_2.png)
  
Even you only have trees in a line, you need to use rope to enclose them. 
  

**Note:**

1.  All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
2.  All input integers will range from 0 to 100.
3.  The garden has at least one tree.
4.  All coordinates are distinct.
5.  Input points have **NO** order. No order required for output.
6.  input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        vector<vector<int> > res;
        sort(points.begin(), points.end(), [](auto &a, auto &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for(auto p : points ) {
            while(res.size() >= 2 && orient(res[res.size()-2], res.back(), p) < 0)
                res.pop_back();
            res.push_back(p);
        }
        for(int i = points.size()-2; i >=0; --i) {
            while(res.size() >= 2 && orient(res[res.size()-2], res.back(), points[i]) < 0) {
                res.pop_back();
            }
            res.push_back(points[i]);
        }
        set<vector<int> > s(res.begin(), res.end());
        return vector<vector<int> > (s.begin(), s.end());
    }
    
    int orient(vector<int> &p, vector<int> &q, vector<int> &r) {
        return (q[1] - p[1]) * (r[0] - p[0]) - (r[1] - p[1]) * (q[0] - p[0]);
    }
};
```
      