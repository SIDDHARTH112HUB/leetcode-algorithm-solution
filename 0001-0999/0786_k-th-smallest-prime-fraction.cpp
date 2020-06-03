//Link: https://leetcode.com/problems/k-th-smallest-prime-fraction/ 
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l = 0, r = 1.0;
        int n = A.size();
        while(l < r) {
            double mid = (l + r) / 2;
            int num = 0, ii, jj;
            double mf = 0.0, max_f = 0.0;
            int j = 0;
            for(int i = 0; i < A.size() - 1; ++i) {
                while(j < A.size() && A[i] * 1.0 / A[j] > mid ) {
                    ++j;
                }
                if(j < A.size()){
                    double t = A[i] * 1.0 / A[j]; 
                    if (t > mf) {
                        mf = t;
                        ii = A[i];
                        jj = A[j];
                    }
                }
                num += n - j;
            }
            if(num == K) {
                
                return {ii, jj};
            }
            else if(num > K)
                r = mid;
            else
                l = mid;
                
        }
        return {};
    }
};