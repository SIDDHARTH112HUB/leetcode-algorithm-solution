//Link: https://leetcode.com/problems/count-numbers-with-unique-digits/ 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if( n<=0) return 1;
        if(n > 10 ) n =10;
        int dp[11] = {0};
        dp[1] = 10;
        //cout<<"begin "<<endl;
        for( int i = 2; i<=n; i++ ){
            int p = 9;
            for(int j = 0; j<i-1; j++){
                p *= (9-j);
            }
            //cout<<p<<endl;
            dp[i] = dp[i-1] + p;
        }
        return dp[n];
    }
};