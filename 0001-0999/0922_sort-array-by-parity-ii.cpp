//Link: https://leetcode.com/problems/sort-array-by-parity-ii/ 
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int o = 1, e=0;
        vector<int> ans(A.size());
        for( int i = 0; i<A.size(); i++ ){
            if( A[i] % 2 == 0){
                ans[e] = A[i];
                e+=2;
            }
            else{
                ans[o] = A[i];
                o+=2;
            }
        }
        return ans;
    }
};