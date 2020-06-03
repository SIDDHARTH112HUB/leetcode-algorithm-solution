//Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/ 
class Solution {
public:
    
    int countPrimeSetBits(int L, int R) {
        int p[33]={0};
    p[2]=1;
    p[3]=1;
    p[5]=1;
    p[7]=1;
    p[11]=1;
    p[13]=1;
    p[17]=1;
    p[19]=1;
    p[23]=1;
    p[29]=1;
    p[31]=1;
    int ans= 0;
        for(int i = L; i<=R; i++){
            int n = i;
            int c = 0;
            while(n>0){
                if( n%2 == 1)
                    c++;
                n/=2;
            }
            if(p[c] == 1){
                ans++;
            }
        }
    
    return ans;
    }
};