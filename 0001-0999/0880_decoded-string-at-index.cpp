//Link: https://leetcode.com/problems/decoded-string-at-index/ 
class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long N = 0,i =0;
        for( ; N < K; i++){
            char c = S[i];
            N = c > '9' ? N+1 : N * (c - '0');
        }
        while( i-- ){
            if( S[i] <= '9'){
                N /= (S[i]-'0');
                K %= N;
                
            }else{
                if( K%(N--) == 0)
                    return S.substr(i, 1);
            }
        }
        return "";
    }
};