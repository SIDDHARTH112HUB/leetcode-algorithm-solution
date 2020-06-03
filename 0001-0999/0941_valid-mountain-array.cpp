//Link: https://leetcode.com/problems/valid-mountain-array/ 
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if( A.size() <= 2) return false;
        int idx = max_element(A.begin(), A.end()) - A.begin();
        if( idx == 0 || idx == A.size() -1 ) return false;
        int l = idx, r = idx;
        while( l > 0 || r <A.size()-1 ){
            if( l > 0 && A[l-1] >= A[l]  )
                return false;
            l--;
            if( r < A.size()- 1 && A[r+1]>=A[r] )
                return false;
            r++;
        }
        return true;
    }
};