[1453.maximum-number-of-darts-inside-of-a-circular-dartboard](https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/)  

You have a very large square wall and a circular dartboard placed on the wall. You have been challenged to throw darts into the board blindfolded. Darts thrown at the wall are represented as an array of `points` on a 2D plane. 

Return the maximum number of points that are within or lie on **any** circular dartboard of radius `r`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/04/29/sample_1_1806.png)

**Input:** points = \[\[-2,0\],\[2,0\],\[0,2\],\[0,-2\]\], r = 2
**Output:** 4
**Explanation:** Circle dartboard with center in (0,0) and radius = 2 contain all points.

**Example 2:**

**![](https://assets.leetcode.com/uploads/2020/04/29/sample_2_1806.png)**

**Input:** points = \[\[-3,0\],\[3,0\],\[2,6\],\[5,4\],\[0,9\],\[7,8\]\], r = 5
**Output:** 5
**Explanation:** Circle dartboard with center in (0,4) and radius = 5 contain all points except the point (7,8).

**Example 3:**

**Input:** points = \[\[-2,0\],\[2,0\],\[0,2\],\[0,-2\]\], r = 1
**Output:** 1

**Example 4:**

**Input:** points = \[\[1,2\],\[3,5\],\[1,-1\],\[2,3\],\[4,1\],\[1,3\]\], r = 2
**Output:** 4

**Constraints:**

*   `1 <= points.length <= 100`
*   `points[i].length == 2`
*   `-10^4 <= points[i][0], points[i][1] <= 10^4`
*   `1 <= r <= 5000`  



**Solution:**  

```cpp

double dis(vector<double> &a, vector<double> b) {

    return sqrt((a[0] - b[0]) *(a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
}

void CircleCenter(double x1,double y1,double x2,double y2,double R,double &x,double &y)  
{  
    double c1 = (x2*x2 - x1*x1 + y2*y2 - y1*y1) / (2 *(x2 - x1));  
    double c2 = (y2 - y1) / (x2 - x1);
    double A = (c2*c2 + 1);  
    double B = (2 * x1*c2 - 2 * c1*c2 - 2 * y1);  
    double C = x1*x1 - 2 * x1*c1 + c1*c1 + y1*y1 - R*R;  
    y = (-B + sqrt(B*B - 4 * A*C)) / (2 * A);
    x = c1 - c2 * y;     
} 
class Solution {
public:
    
    int numPoints(vector<vector<int>>& points, int r) {
        int ans = 1;
        vector<vector<double> > ps(points.size());
        for(int i = 0; i < points.size(); ++i) {
            ps[i].push_back(points[i][0]);
            ps[i].push_back(points[i][1]);
        }
        for(int i = 0; i < points.size(); ++i) {
            for(int j = 0; j < points.size(); ++j) {
                auto p1 = ps[i], p2 = ps[j];
                if(i == j || dis(p1, p2)  > r * 2) continue;
                double x, y;
                int res = 0;
                CircleCenter(p1[0], p1[1], p2[0], p2[1], r, x, y);
                //cout<<i<<" "<<j<<endl;
                //cout<<" cir:"<<x<<" "<<y<<endl;
                for(int k = 0; k < points.size(); ++k) {
                    if(dis(ps[k], {x, y}) <= r + 0.0000000001) ++res;
                }
                ans = max(ans, res);
            }
        }
        return ans;
    }
};
```
      