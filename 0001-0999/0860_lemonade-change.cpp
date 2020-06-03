//Link: https://leetcode.com/problems/lemonade-change/ 
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten =0;
        for( int n:bills){
            if( n == 10 )
                ten++;
            else if( n == 5 )
                five++;
            int r = n-5;
            if( r > 10){
                if( ten > 0 ){
                    r -= 10;
                    ten--;
                }
            }
            if( r >=5 ){
                five -= (r/5);
            }
            if( five < 0 )
                return false;
        }
        return true;
    }
};