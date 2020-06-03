//Link: https://leetcode.com/problems/best-sightseeing-pair/ 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = INT_MIN, mx = A[0];
        for( int i = 1; i < A.size(); i++ ){
            ans = max(ans, A[i]-i + mx);
            mx = max(A[i]+i, mx);
        }
        return ans;
    }
};