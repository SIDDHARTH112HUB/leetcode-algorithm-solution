//Link: https://leetcode.com/problems/elimination-game/ 
class Solution {
public:
    int lastRemaining(int n) {
        int res = 1, step = 1;
        while(step * 2 <=n ) {
            res += step;
            step *= 2;
            if(step * 2 > n) break;
            if( (n/step) % 2 ) res += step;
            step *= 2;
        }
        return res;
    }
};