//Link: https://leetcode.com/problems/valid-perfect-square/ 
class Solution {
public:
    bool isPerfectSquare(int num) {
        if( num == 0 ) return true;
        int sq = 1;
        while( sq >= 1 && (sq*sq) < num ){
            sq++;
        }
        return sq*sq == num;
    }
};