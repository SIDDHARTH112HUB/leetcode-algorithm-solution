//Link: https://leetcode.com/problems/arranging-coins/ 
class Solution {
public:
    int arrangeCoins(int n) {
        if( n <= 0) return 0;
        int step = 1;
        while( n >= step ){
            n -= step;
            ++step;
        }
        return step-1;
    }
};