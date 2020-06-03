//Link: https://leetcode.com/problems/k-th-symbol-in-grammar/ 
class Solution {
public:
    int kthGrammar(int N, int K) {
        int ans[4] = {0,1,1,0};
        int ans_ver[4]=  {1,0,0,1};
        
        int count = 0 ;
        while( K > 4 ){
            int n = 1;
            while( n * 2 < K ){
            n *= 2;
            }
            K -= n;
            count++;
            n /= 2;
        }
        if( count % 2 == 0 )
            return ans[K-1];
        else
            return ans_ver[K-1];
    }
};