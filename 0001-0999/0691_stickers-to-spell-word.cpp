//Link: https://leetcode.com/problems/stickers-to-spell-word/ 
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = target.size();
        int dp[1 << n];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < (1<<n); ++i) {
            
            if(dp[i] == -1) continue;
            for(auto &sticker : stickers) {
                int cur = i;
                for(char c : sticker) {
                    for(int j = 0; j < target.size(); ++j ) {
                        if(c == target[j] && !(cur & (1 << j)) ) {
                            cur |= 1 << j;
                            break;
                        }
                    }
                }
                if(dp[cur] == -1) dp[cur] = INT_MAX;
                dp[cur] = min(dp[cur], dp[i] + 1);
            }
        }
        return dp[(1<<n) - 1];
    }
};