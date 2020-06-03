//Link: https://leetcode.com/problems/buddy-strings/ 
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if( A.size() != B.size() ) return false;
        if( A == B ){
            int hash[128] = {0};
            for( char c : A){
                hash[c]++;
            }
            for(int i = 0; i<128; i++){
                if( hash[i] %2 == 0 && hash[i]>0 )
                    return true;
            }
            return false;
        }
        int cnt=0;
        int i1 = -1, i2 =-1;
        for( int i = 0; i<A.size(); i++ ){
            if( A[i] != B[i]){
                cnt++;
                if(cnt>2)
                    return false;
                if(i1==-1){
                    i1 = i;
                }else{
                    i2 = i;
                    if( A[i1] != B[i] || B[i1] != A[i] )
                        return false;
                }
            }
        }
        if( i1 != -1 && i2 == -1 )
            return false;
        return cnt == 2;
    }
};