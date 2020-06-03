//Link: https://leetcode.com/problems/two-sum-less-than-k/ 
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int ans = -1;
        for(int i = 0; i < A.size(); i ++){
            for(int j = i + 1; j < A.size(); j++){
                if(A[i] + A[j] < K)
                    ans = max(ans, A[i]+A[j]);
            }
        }
        return ans;
    }
};