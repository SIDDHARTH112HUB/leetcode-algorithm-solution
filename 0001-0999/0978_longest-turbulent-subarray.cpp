//Link: https://leetcode.com/problems/longest-turbulent-subarray/ 
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int ans = 0, cur = 1;
        for( int i = 0; i<A.size()-1; i++){
            if( i % 2 == 0 && A[i] < A[i+1]){
                cur++;
            }else if( i % 2 == 1 && A[i] > A[i+1])
                cur++;
            else{
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(cur, ans);
        cur = 1;
        for( int i = 0; i<A.size()-1; i++){
            if( i % 2 == 1 && A[i] < A[i+1]){
                cur++;
            }else if( i % 2 == 0 && A[i] > A[i+1])
                cur++;
            else{
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(cur, ans);
        return ans;
    }
};