//Link: https://leetcode.com/problems/monotonic-array/ 
class Solution {
public:
    /*bool isMonotonic(vector<int>& A) {
        int res = -1;
        for( int i = 1; i<A.size(); i++){
            if( A[i] == A[i-1])
                continue;
            if( res == -1 ){
                res = (A[i] > A[i-1]);
                continue;
            }
            if( res != (A[i] > A[i-1]) )
                return false;
        }
        return true;
    }*/
    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        for(int i = 1; i<A.size(); i++){
            inc &= A[i] >= A[i-1];
            dec &= A[i] <= A[i-1];
        }
        return inc ||dec;
    }
};