//Link: https://leetcode.com/problems/sum-of-subsequence-widths/ 
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        long long M = 1000000007, c = 1,ans = 0;
        int n = A.size();
        for( int i = 0; i < A.size(); i++ ){
            ans = (ans + ( (A[i] - (A[n-i-1]) )*c+M)%M)%M;
            c = (c<< 1)%M;
        }
        return (ans+M) % M;
    }
};