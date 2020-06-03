//Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/ 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size(), res = 0;
        vector<unordered_map<long long, long long> > dp(size);
        for(int i = 0; i < A.size(); ++i) {
            for(int j = i + 1; j < A.size(); ++j) {
                long long diff = (long long)A[j] - (long long)A[i];
                ++dp[j][diff];
                if(dp[i].count(diff)){
                    res += dp[i][diff];
                    dp[j][diff] += dp[i][diff];
                }
            }
        }
        return res;
    }
};