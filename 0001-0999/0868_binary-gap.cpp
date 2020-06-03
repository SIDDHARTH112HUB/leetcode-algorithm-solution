//Link: https://leetcode.com/problems/binary-gap/ 
class Solution {
public:
    int binaryGap(int N) {
        int prev = -1;
        int idx = 0;
        int ans = 0;
        while( N > 0 ){
            if( N & 1 ){
                if( prev != -1)
                    ans = max( idx - prev, ans);
                prev = idx;
            }
            idx++;
            N = N >> 1;
        }
        return ans;
    }
};