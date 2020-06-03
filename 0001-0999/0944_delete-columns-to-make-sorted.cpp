//Link: https://leetcode.com/problems/delete-columns-to-make-sorted/ 
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int ans = 0;
        for( int i = 0; i<1000; i++ ){
            for( int j = 0; j<A.size()-1; j++){
                string &prev = A[j];
                string &cur = A[j+1];
                if( prev.size() <= i || cur.size() <=i )
                    continue;
                if( prev[i] > cur[i]){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};