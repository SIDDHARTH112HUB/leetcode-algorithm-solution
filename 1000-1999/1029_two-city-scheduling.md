[1029.two-city-scheduling](https://leetcode.com/problems/two-city-scheduling/)  

There are `2N` people a company is planning to interview. The cost of flying the `i`\-th person to city `A` is `costs[i][0]`, and the cost of flying the `i`\-th person to city `B` is `costs[i][1]`.

Return the minimum cost to fly every person to a city such that exactly `N` people arrive in each city.

**Example 1:**

  
**Input:** \[\[10,20\],\[30,200\],\[400,50\],\[30,20\]\]
  
**Output:** 110
  
**Explanation:** 
  
The first person goes to city A for a cost of 10.
  
The second person goes to city A for a cost of 30.
  
The third person goes to city B for a cost of 50.
  
The fourth person goes to city B for a cost of 20.
  

  
The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
  

**Note:**

1.  `1 <= costs.length <= 100`
2.  It is guaranteed that `costs.length` is even.
3.  `1 <= costs[i][0], costs[i][1] <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](auto &a, auto &b){
            return abs(a[0] - a[1]) > abs(b[0] - b[1]);
        });
        int n = costs.size() / 2;
        int a = 0, b = 0;
        int ans = 0;
        for(int i = 0; i < costs.size(); ++i) {
            auto &c = costs[i];
            if(a == n || b == n) {
                ans += a == n ? c[1] : c[0];
                continue;
            }
            if(c[0] > c[1]) {
                ++b; ans += c[1];
            }else{
                ++a; ans += c[0];
            }
                
        }
        return ans;
    }
};
```
      