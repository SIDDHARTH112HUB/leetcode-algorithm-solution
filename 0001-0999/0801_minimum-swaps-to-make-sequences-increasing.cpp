//Link: https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/ 
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        unsigned int keep[A.size()];
        unsigned int swap[A.size()];
        memset(keep, 0xff, sizeof(keep));
        memset(swap, 0xff, sizeof(swap));
        keep[0] = 0;
        swap[0] = 1;
        for( int i = 1; i< A.size(); i++ ){
            int a = A[i];
            int b = B[i];
            if( a > A[i-1] && b > B[i-1]){
                keep[i] = keep[i-1];
                swap[i] = swap[i-1] + 1;
            }
            if( a > B[i-1] && b > A[i-1]){
                keep[i] = min(keep[i], swap[i-1] );
                swap[i] = min(swap[i], keep[i-1] + 1);
            }
        }
        return min(keep[A.size()-1], swap[A.size()-1] );
    }
};