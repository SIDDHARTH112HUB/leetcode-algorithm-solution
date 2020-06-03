//Link: https://leetcode.com/problems/rotate-string/ 
class Solution {
public:
    bool rotateString(string A, string B) {
        if( A.length()== 0 ) return true;
        if( A.length() == 1 && A[0] == B[0] ) return true;
        for( int i = 0; i<A.length(); i++){
            if( B[0] == A[i] ){
                int right = i;
                int b_left = 0;
                while(right<A.size() && A[right] == B[b_left]){
                    right++;
                    b_left++;
                }
                if(b_left == A.length())
                    return true;
                if( right == A.length()){
                    int a_left = 0;
                    while(b_left<B.length() && B[b_left] == A[a_left]){
                        a_left++;
                        b_left++;
                    }
                    if( b_left == B.length())
                        return true;
                }
            }
        }
        return false;
    }
};