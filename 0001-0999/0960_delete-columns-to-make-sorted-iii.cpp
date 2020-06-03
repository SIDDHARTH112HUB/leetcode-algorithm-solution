//Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/ 
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int len = A[0].size();
        vector<int> dp(len, 1);
        int ans = len - 1;
        for( int i = 0; i < len; i++){
            for( int j = 0; j < i; j++){
                int k = 0;
                for( ; k < n; k++){
                    if( A[k][j] > A[k][i] ) break;
                }
                if( k == n && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] +1;
                }
            }
            ans = min( ans, len - dp[i]);
        }
        return ans;
    }
};