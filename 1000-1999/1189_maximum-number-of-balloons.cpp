//Link: https://leetcode.com/problems/maximum-number-of-balloons/ 
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(128);
        for(auto c : text)
            ++cnt[c];
        string s = "balloon";
        int ans = INT_MAX;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == 'l' || s[i] == 'o') {
                ans = min(ans, cnt[s[i]] / 2);
            }else
                ans = min(ans, cnt[s[i]]);
        }
        return ans;
    }
};