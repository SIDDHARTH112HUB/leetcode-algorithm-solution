[1515.best-position-for-a-service-centre](https://leetcode.com/problems/best-position-for-a-service-centre/)  

A delivery company wants to build a new service centre in a new city. The company knows the positions of all the customers in this city on a 2D-Map and wants to build the new centre in a position such that **the sum of the euclidean distances to all customers is minimum**.

Given an array `positions` where `positions[i] = [xi, yi]` is the position of the `ith` customer on the map, return _the minimum sum of the euclidean distances_ to all customers.

In other words, you need to choose the position of the service centre `[xcentre, ycentre]` such that the following formula is minimized:

![](https://assets.leetcode.com/uploads/2020/06/25/q4_edited.jpg)

Answers within `10^-5` of the actual value will be accepted.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/06/25/q4_e1.jpg)

  
**Input:** positions = \[\[0,1\],\[1,0\],\[1,2\],\[2,1\]\]
  
**Output:** 4.00000
  
**Explanation:** As shown, you can see that choosing \[xcentre, ycentre\] = \[1, 1\] will make the distance to each customer = 1, the sum of all distances is 4 which is the minimum possible we can achieve.
  

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/06/25/q4_e3.jpg)

  
**Input:** positions = \[\[1,1\],\[3,3\]\]
  
**Output:** 2.82843
  
**Explanation:** The minimum possible sum of distances = sqrt(2) + sqrt(2) = 2.82843
  

**Example 3:**

  
**Input:** positions = \[\[1,1\]\]
  
**Output:** 0.00000
  

**Example 4:**

  
**Input:** positions = \[\[1,1\],\[0,0\],\[2,0\]\]
  
**Output:** 2.73205
  
**Explanation:** At the first glance, you may think that locating the centre at \[1, 0\] will achieve the minimum sum, but locating it at \[1, 0\] will make the sum of distances = 3.
  
Try to locate the centre at \[1.0, 0.5773502711\] you will see that the sum of distances is 2.73205.
  
Be careful with the precision!
  

**Example 5:**

  
**Input:** positions = \[\[0,1\],\[3,2\],\[4,5\],\[7,6\],\[8,9\],\[11,1\],\[2,12\]\]
  
**Output:** 32.94036
  
**Explanation:** You can use \[4.3460852395, 4.9813795505\] as the position of the centre.
  

**Constraints:**

*   `1 <= positions.length <= 50`
*   `positions[i].length == 2`
*   `0 <= positions[i][0], positions[i][1] <= 100`  



**Solution:**  

```cpp
double limit = 0.00001; 
struct Point { 
    double x, y; 
    Point(){}
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};
Point test_point[] = { { -1.0, 0.0 }, { 0.0, 1.0 }, { 1.0, 0.0 }, { 0.0, -1.0 } }; 

class Solution {
public:
    double distanceSum(Point p, const vector<Point> &arr) { 
        int n = arr.size();
        double sum = 0; 
        for (int i = 0; i < n; i++) { 
            double distx = abs(arr[i].x - p.x); 
            double disty = abs(arr[i].y - p.y); 
            sum += sqrt((distx * distx) + (disty * disty)); 
        } 
        return sum; 
    } 

    double helper(vector<Point> &arr) {
        int n = arr.size();
        Point current_point;
        for (int i = 0; i < n; i++) { 
            current_point.x += arr[i].x; 
            current_point.y += arr[i].y; 
        }
        current_point.x /= n; 
        current_point.y /= n;
        double minimum_distance = distanceSum(current_point, arr); 
        int k = 0; 
        while (k < n) { 
            for (int i = 0; i < n, i != k; i++) { 
                Point newpoint; 
                newpoint.x = arr[i].x; 
                newpoint.y = arr[i].y; 
                double newd = distanceSum(newpoint, arr); 
                if (newd < minimum_distance) { 
                    minimum_distance = newd; 
                    current_point.x = newpoint.x; 
                    current_point.y = newpoint.y; 
                } 
            } 
            k++; 
        } 
        double test_dis = 1000; 
        int flag = 0; 
        while (test_dis > limit) {
            flag = 0;
            for (int i = 0; i < 4; i++) {
                Point newpoint; 
                newpoint.x = current_point.x + (double)test_dis * test_point[i].x; 
                newpoint.y = current_point.y + (double)test_dis * test_point[i].y; 
                double newd = distanceSum(newpoint, arr);
                if (newd < minimum_distance) { 
                    minimum_distance = newd; 
                    current_point.x = newpoint.x; 
                    current_point.y = newpoint.y; 
                    flag = 1; 
                    break; 
                } 
            } 
            if (flag == 0) 
                test_dis /= 2; 
        }
        return minimum_distance;
    } 
    double getMinDistSum(vector<vector<int>>& positions) {
        vector<Point> arr;
        for(auto &p : positions) {
            arr.push_back(Point(p[0], p[1]));
        }
        return helper(arr);
    }
};
```
      