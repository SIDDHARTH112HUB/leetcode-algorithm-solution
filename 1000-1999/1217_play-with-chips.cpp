//Link: https://leetcode.com/problems/play-with-chips/ 
class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        if(chips.size() <= 1 ) return 0;
        int ans = INT_MAX;
        for(int i = 0; i < chips.size(); ++i) {
            int res = 0;
            for(int j = 0; j < chips.size(); ++j) {
                if(i == j) continue;
                res += abs(chips[i] - chips[j]) % 2 ? 1 : 0;
            }
            ans = min(ans, res);
        }
        return ans;
    }
};