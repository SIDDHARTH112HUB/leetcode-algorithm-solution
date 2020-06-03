//Link: https://leetcode.com/problems/fixed-point/ 
class Solution {
public:
    int fixedPoint(vector<int>& A) {
        if(A.size() == 0) return -1;
        int l = 0, r = A.size() - 1;
        while(l < r) {
            int mid = (l + r)/2;
            if(A[mid] >= mid) r = mid;
            else if(A[mid] < mid) l = mid + 1;
        }
        return A[l] != l ? -1 : l;
    }
};