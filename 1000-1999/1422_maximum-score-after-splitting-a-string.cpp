//Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/ 
class Solution {
public:
    int maxScore(string s) {
        int one = 0, zero = 0, ans = 0;
        for(auto c : s)
            one += c == '1';
        for(int i = 0; i < s.size() - 1; ++i) {
            one -= s[i] == '1';
            zero += s[i] == '0';
            ans = max(ans, one + zero);
        }
        return ans;
    }
};