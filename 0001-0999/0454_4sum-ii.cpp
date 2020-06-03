//Link: https://leetcode.com/problems/4sum-ii/ 
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        //sort(A.begin(), A.end());
        //sort(B.begin(), B.end());
        unordered_map<int, int> m;
        for(int i = 0; i < C.size(); ++i) {
            for(int j = 0; j < D.size(); ++j){
                ++m[C[i]+ D[j]];
            }
        }
        int ans = 0;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < B.size(); ++j) {
                ans += m[-(A[i] + B[j])];
            }
        }
        return ans;
    }
};