//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/ 
class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        int n = A.size();
        if( n == 0 ) return 0;
        int cnt = 1;
        for( int i = 1; i<n ;i++)
        {
            if( A[cnt-1] == A[i])
            {
                continue;
            }
            A[cnt++] = A[i];
        }
        return cnt;
    }
};