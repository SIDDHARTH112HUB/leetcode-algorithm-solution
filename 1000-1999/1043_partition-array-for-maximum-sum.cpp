//Link: https://leetcode.com/problems/partition-array-for-maximum-sum/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > m;
    int maxSumAfterPartitioning(vector<int>& A, int K) {
       return solve(A, 0, K);
    }
    
    int solve(vector<int>& A, int idx, int K) {
        if (idx == A.size())
            return 0;
        if (m[idx].count(K))
            return m[idx][K];
        
        
        int mx = 0;
        int ans = 0;
        for( int i = idx; i < A.size() && i < idx+K; ++i) {
            mx = max(mx, A[i]);
            ans = max(ans, mx * (i - idx+1) + solve(A, i + 1, K));
        }
        m[idx][K] = ans;
        return ans;
    }
};