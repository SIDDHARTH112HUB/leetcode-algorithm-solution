//Link: https://leetcode.com/problems/longest-repeating-substring/ 
class Solution {
public:
    
    int longestRepeatingSubstring(string S) {
        int ans = 0;
        for(int i = 0; i < S.size(); ++i) {
            ans = max(ans, kmp(S, i));
        }
        return ans;
    }
    
    int kmp(string &s, int start) {
        int j = start;
        vector<int> p(s.size());
        int res = 0;
        for(int i = start + 1; i < s.size(); ++i) {
            while(j > start && s[j] != s[i]) j = p[j - 1] + start;
            if(s[j] == s[i]) p[i] = (++j) - start;
            res = max(res, j - start);
        }
        return res;
    }
};