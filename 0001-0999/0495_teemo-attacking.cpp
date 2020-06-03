//Link: https://leetcode.com/problems/teemo-attacking/ 
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if( timeSeries.size() == 0 )return 0;
        int ans = duration;
        for( int i = 0; i<timeSeries.size()-1; i++ )
            ans += min(timeSeries[i+1]-timeSeries[i], duration);
        return ans;
    }
};