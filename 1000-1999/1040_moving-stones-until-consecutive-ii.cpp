//Link: https://leetcode.com/problems/moving-stones-until-consecutive-ii/ 
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int h = max(stones[n-2] - stones[0] - n + 2, stones.back() - stones[1] - n + 2);
        int low = INT_MAX;
        int j = 0;
        for(int i = 0; i < stones.size(); ++i) {
            while(stones[i] - stones[j] >=n) ++j;
            int cnt = i - j + 1;
            if(cnt == n - 1 && stones[i] - stones[j] == n - 2 )
                low = min(low, 2);
            else
                low = min(low, n - cnt);
        }
        return {low, h};
    }
};