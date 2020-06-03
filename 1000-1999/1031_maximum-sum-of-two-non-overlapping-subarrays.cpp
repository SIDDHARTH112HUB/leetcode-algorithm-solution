//Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/ 
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for(int i = 1; i < A.size(); ++i) {
            A[i] += A[i-1];
        }
        int ans = 0;
        for(int i = L - 1; i < A.size(); ++i) {
            int res = 0;
            int a = A[i] - (i - L >= 0 ?A[i - L] : 0);
            for(int j = M - 1; j < A.size() && j <= i - L; ++j) {
                res = max(res, a + A[j] - (j - M >= 0 ? A[j - M] : 0));
            }
            for(int j = i + M; j < A.size() &&  j > i; ++j) {
                res = max(res, a + A[j] - A[j - M]);
            }
            ans = max(ans, res);
        }
        return ans;
    }
};