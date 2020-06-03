//Link: https://leetcode.com/problems/ones-and-zeroes/ 
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for(auto &str: strs){
            int z = 0, o = 0;
            for(char c : str)
                c == '0' ? ++z : ++o;
            for(int i = m; i >= z; --i) {
                for(int j = n; j >= o; --j) {
                    dp[i][j] = max(dp[i][j], dp[i-z][j-o] + 1);
                }
            }
        }
        return dp[m][n];
    }
    /*
    int findMaxForm(vector<string>& strs, int m, int n) {
        unordered_map<int, int> memo, dp;
        int ans = 0;
        memo[0] = 0;
        dp[0] = 0;
        for(int i = 1; i <= strs.size(); ++i) {
            int z = 0, o = 0;
            for(char c : strs[i-1])
                c == '0' ? ++z : ++o;
            for(auto &it : memo) {
                int nm = (it.first & 0xFFFF) + z;
                int nn = (it.first >> 16) + o;
                if(nm > m || nn > n) continue;
                int hash = nm | (nn << 16);
                dp[hash] = max(dp[hash], it.second + 1);
                ans = max(ans, dp[hash]);
            }
            memo = dp;
        }
        return ans;
    }*/
};