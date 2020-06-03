//Link: https://leetcode.com/problems/min-cost-climbing-stairs/ 
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
