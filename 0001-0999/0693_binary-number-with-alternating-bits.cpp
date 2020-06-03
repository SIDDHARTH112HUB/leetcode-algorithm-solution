//Link: https://leetcode.com/problems/binary-number-with-alternating-bits/ 
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag = n %2;
        int f = flag;
        while(n > 0){
            if( f == n % 2){
                n = n>>1;
                if( f == 0 )
                    f = 1;
                else
                    f = 0;
            }
            else
                return false;
        }
        return true;
    }
};