[746.min-cost-climbing-stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)  

On a staircase, the `i`\-th step has some non-negative cost `cost[i]` assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

**Example 1:**  

  
**Input:** cost = \[10, 15, 20\]
  
**Output:** 15
  
**Explanation:** Cheapest is start on cost\[1\], pay that cost and go to the top.
  

**Example 2:**  

  
**Input:** cost = \[1, 100, 1, 1, 1, 100, 1, 1, 100, 1\]
  
**Output:** 6
  
**Explanation:** Cheapest is start on cost\[0\], and only step on 1s, skipping cost\[3\].
  

**Note:**  

1.  `cost` will have a length in the range `[2, 1000]`.
2.  Every `cost[i]` will be an integer in the range `[0, 999]`.  



**Solution:**  

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int st1 = cost[0];
        int st2 = cost[1];
        int ans = min(st1, st2);
        int size = cost.size();
        printf("size %d \n", size);
        for( int i = 2; i<size; i++){
            //if( cost[i-1] > cost[i-2]  )
                ans = min(cost[i-1]+cost[i], (cost[i-2]+cost[i]));
            //else
            //    ans = min(cost[i-1]+cost[i], (cost[i-2]));
            cost[i] = ans;
            printf("cost[i-1]:%d ,i-2: %d, ans: %d \n",cost[i-1], cost[i-2], ans);
        }
        return min(ans, cost[size-2]);
    }
};

```
      