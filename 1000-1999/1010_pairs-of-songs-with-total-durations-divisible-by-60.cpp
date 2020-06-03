//Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/ 
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> cnt(60);
        for(int t : time)
            ++cnt[t%60];
        int ans = 0;
        for(int i = 0; i <=30; ++i){
            if(i % 30 == 0) {
                ans += cnt[i] * (cnt[i] - 1) / 2;
            }else{
                ans += cnt[i] * (cnt[60 - i]);
            }
        }
        return ans;
    }
};