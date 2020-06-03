//Link: https://leetcode.com/problems/sum-of-square-numbers/ 
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c == 0) return true;
        int sqc = sqrt(c);
        for(int i = 1; i <= sqc; ++i) {
            int b = c - i * i;
            int sb = sqrt(b);
            if(sb * sb + i * i == c)
                return true;
        }
        return false;
    }
};