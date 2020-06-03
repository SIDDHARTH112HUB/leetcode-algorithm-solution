//Link: https://leetcode.com/problems/rotated-digits/ 
class Solution {
public:
    int rotatedDigits(int N) {
        int num[10] = {0,1,5,-1,-1,2,9,-1,8,6};
        int ans = 0;
        for( int i = 1; i<=N; i++){
            int n = i;
            int new_num = 0;
            int bit=1;
            
            while(n>0){
                int a=n%10;
                n/=10;
                if(num[a] <0 ){
                    new_num = i;
                    break;
                }
                new_num = new_num+num[a]*(bit);
                bit*=10;
            }
           // printf("%d %d\n", new_num, i);
            if( new_num != i )
                ans++;
        }
        return ans;
    }
};