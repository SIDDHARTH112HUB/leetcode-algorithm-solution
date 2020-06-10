//Link: https://leetcode.com/problems/russian-doll-envelopes/ 
class Solution {
public:
    int maxEnvelopes(vector<vector<int> >& envelopes) {
        if( envelopes.size() == 0 ) return 0;
        sort(envelopes.begin(), envelopes.end(), [](auto&a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int> dp;
        
        int ans = 1;
        for( int i = 0; i< envelopes.size(); i++){
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            if(it == dp.end()) {
                dp.push_back(envelopes[i][1]);
            }else {
                *it = envelopes[i][1];
            }
        }
        return dp.size();
    }
};
