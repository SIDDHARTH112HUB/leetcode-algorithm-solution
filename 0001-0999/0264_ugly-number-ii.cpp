//Link: https://leetcode.com/problems/ugly-number-ii/ 
class Solution {
public:
    int nthUglyNumber(int n) {
        if( n == 0 ) return 0;
        int next2=2, next3=3, next5=5;
        int i2=0, i3=0, i5=0;
        int dp[n] = {0};
        dp[0] = 1;
        for( int i = 1; i<n; i++){
            int next_num = min(next2, min(next3, next5));
            dp[i] = next_num;
            //cout<<next_num<<" ";
            if( next_num == next2 ){
                i2++;
                next2 = dp[i2] * 2;
            }
            if( next_num == next3){
                i3++;
                next3 = dp[i3] * 3;
            }
            if( next_num == next5){
                i5++;
                next5 = dp[i5] * 5;
            }
        }
        return dp[n-1];
    }
};