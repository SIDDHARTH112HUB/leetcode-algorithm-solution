//Link: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/ 
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if(A.size() == 0) return 0;
        sort(A.begin(), A.end());
        int cnt = 0;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] < 0 && cnt < K) {
                A[i] = -A[i];
                ++cnt;
            }
        }
        sort(A.begin(), A.end());
        K -= cnt;
        if(K % 2) {
            A[0] = -A[0];
        }
        return accumulate(A.begin(), A.end(), 0);
    }
};