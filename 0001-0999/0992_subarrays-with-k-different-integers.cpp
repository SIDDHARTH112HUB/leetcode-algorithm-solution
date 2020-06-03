//Link: https://leetcode.com/problems/subarrays-with-k-different-integers/ 
#define umii unordered_map<int, int> 
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return f(A, K) - f(A, K - 1);
    }
    int f(vector<int> &A, int K) {
        int e = 0, b = 0, ans = 0;
        umii m;
        while( e < A.size()) {
            if(m[A[e++]]++ == 0)
                --K;
            while(b < A.size() && K < 0) {
                if(--m[A[b++]] == 0)
                    ++K;
            }
            ans += e - b;
        }
        return ans;
    }
};