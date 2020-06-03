//Link: https://leetcode.com/problems/coin-path/ 
class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        if(A.back() == -1) return {};
        if(A.size() == 1) return {1};
        vector<int> dp(A.size(), INT_MAX), path(A.size(), INT_MAX), len(A.size(), 0);
        dp[0] = 0;
        path[0] = INT_MAX;
        for(int i = 0; i < A.size(); ++i) {
            if(dp[i] == INT_MAX) continue;
            for(int j = i + 1; j <= i + B; ++j) {
                if(j >= A.size()) break;
                if(A[j] == -1) continue;
                int cost = dp[i] + A[j];
                
                if(dp[j] > cost || (dp[j] == cost && len[j] < len[i] + 1)) {
                    path[j] = i;
                    len[j] = len[i] + 1;
                    dp[j] = cost;
                }
            }
        }
        if(path.back() == INT_MAX) return {};
        vector<int> ans;
        int idx = A.size() - 1;
        while(path[idx] != INT_MAX) {
            ans.push_back(idx + 1);
            idx = path[idx];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};