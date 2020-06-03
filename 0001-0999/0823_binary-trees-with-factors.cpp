//Link: https://leetcode.com/problems/binary-trees-with-factors/ 
class Solution {
public:
    int M = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& A) {
        unordered_map<long, long> m;
        sort(A.begin(), A.end());
        for(int i = 0; i < A.size(); ++i) {
            m[A[i]] += 1;
            for(int j = 0; j < i; ++j) {
                long mod = A[i] % A[j];
                long div = A[i] / A[j];
                if(mod == 0 && m.count(div)) {
                    m[A[i]] += (m[A[j]] * m[div])%M;
                }
            }
        }
        long ans = 0;
        for(auto &it : m)ans = (ans + it.second) % M;
        return ans;
    }
};