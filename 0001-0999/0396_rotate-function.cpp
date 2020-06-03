//Link: https://leetcode.com/problems/rotate-function/ 
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long sum = 0;
        long long F = 0;
        
        for(int i = 0; i < A.size(); ++i) {
            sum += A[i];
            F += A[i] * i;
        }
        long long ans = F;
        for(int i = 1; i < A.size(); ++i) {
            F += sum - A.size() * A[A.size() - i];
            ans = max(F, ans);
        }
        return ans;
    }
};