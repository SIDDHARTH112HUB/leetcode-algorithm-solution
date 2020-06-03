//Link: https://leetcode.com/problems/minimum-cost-for-tickets/ 
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int pass[3] = {1, 7, 30};
        vector<int> dp(days.size(), INT_MAX);
        for( int i = 0; i < days.size(); i++ ){
            int day = days[i];
            int diff = day - days[0]+1;
            for( int j = 0; j < costs.size(); j++){
                if( diff>=pass[j] ){
                    int idx = lower_bound( days.begin(), days.end(), day-pass[j]) - days.begin();
                    if( days[idx] != day-pass[j] )
                        --idx;
                    dp[i] = min((idx>=0?dp[idx]:0) + costs[j], dp[i]);
                }else{
                    dp[i] = min(dp[i], costs[j]);
                }
            }
        }
        return dp.back();
    }
};