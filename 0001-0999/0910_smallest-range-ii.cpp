//Link: https://leetcode.com/problems/smallest-range-ii/ 
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort( A.begin(), A.end());
        int mx = A.back(), mn = A[0];
        int ans = mx-mn;
        for( int i = 0; i< A.size()-1; i++){
            mx = max( mx, A[i] + 2 * K);
            mn = min( A[i+1], A[0] + 2 * K);
            ans = min( ans, mx-mn);
        }
        return ans;
    }
};