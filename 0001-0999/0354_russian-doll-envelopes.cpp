//Link: https://leetcode.com/problems/russian-doll-envelopes/ 
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if( envelopes.size() == 0 ) return 0;
        sort(envelopes.begin(), envelopes.end());
        int dp[envelopes.size()] = {0};
        dp[0] = 1;
        int ans = 1;
        for( int i = 1; i< envelopes.size(); i++){
            dp[i] = 1;
            for( int j = 0; j<i; j++){
                if( envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};