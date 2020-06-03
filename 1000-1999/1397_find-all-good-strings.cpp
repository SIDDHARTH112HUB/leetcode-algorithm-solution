//Link: https://leetcode.com/problems/find-all-good-strings/ 
class Solution {
public:
    long long dp[501][51][2][2];
    vector<int> lps;
    int findGoodStrings(int n, string s1, string s2, string evil) {
        memset(dp, -1, sizeof(dp));
        lps = calLPS(evil);
        return solve(s1, s2, evil, 0, 0, true, true);
    }

    long long solve(string &s1, string &s2, string &evil, int i, int evilMatch, bool leftBound, bool rightBound) {
        if(evilMatch == evil.size()) return 0;
        if(i == s1.size()) return 1;
        if(dp[i][evilMatch][leftBound][rightBound] >= 0) return dp[i][evilMatch][leftBound][rightBound];
        char from = leftBound ? s1[i] : 'a';
        char to   = rightBound ? s2[i] : 'z';
        long long res = 0;
        for(int c = from; c<=to; ++c) {
            int j = evilMatch;
            while(j > 0 && c != evil[j]) j = lps[j-1];
            if(c == evil[j]) ++j;
            res += solve(s1, s2, evil, i + 1, j, leftBound && (c == from) , rightBound && ( c== to));
            res %= 1000000007;
        }
        dp[i][evilMatch][leftBound][rightBound] = res;
        return res;
    }
    vector<int> calLPS(string &s) {
        vector<int> lps(s.size());
        for(int i = 1, j = 0; i < s.size(); ++i) {
            while(j > 0 && s[i] != s[j]) j = lps[j-1];
            if(s[i] == s[j]) lps[i] = ++j;
        }
        return lps;
    }
};