//Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/ 
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int ans = 0;
        for( int i = 0; i <= A.size() - K; i++){
            if( A[i] % 2 == 0 ){
                for( int j = i; j<K+i; j++)
                    A[j] = A[j]==0?1:0;
                ++ans;
            }
        }
        return accumulate(A.begin(), A.end(), 0) == A.size() ? ans: -1;
    }
};