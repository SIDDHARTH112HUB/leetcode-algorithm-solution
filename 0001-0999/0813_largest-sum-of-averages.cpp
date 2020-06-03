//Link: https://leetcode.com/problems/largest-sum-of-averages/ 
class Solution {
public:
    double dp[201][201] = {0};
    
    double largestSumOfAverages(vector<int>& A, int K) {
        return search(A, A.size(), K);
    }
    
    double search(vector<int>& A, int n, int k) {
        if( dp[n][k] != 0 ) return dp[n][k];
        if (n < k ) return 0;
        if (k == 1) {
            return accumulate(A.begin(), A.begin()+n, 0) * 1.0 / n;
        }
        double cur = 0;
        for (int i = n-1; i >= 0; i--){
            cur += A[i];
            dp[n][k] = max(dp[n][k], search(A, i, k-1) + cur / (n-i) );
        }
        return dp[n][k];
    }
};