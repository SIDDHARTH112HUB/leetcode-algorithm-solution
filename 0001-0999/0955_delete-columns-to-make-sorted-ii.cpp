//Link: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/ 
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        int n  = A.size();
        int len = A[0].size();
        vector<string> B(n);
        for( int i = 0; i< len ; i++){
            for( int j = 0; j < n; j++){
                B[j] += A[j][i];
                if( j > 0 ){
                    if( B[j] < B[j-1]){
                        for( int k = 0; k <=j; k++){
                            B[k].pop_back();
                        }
                        ans++;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};