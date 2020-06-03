//Link: https://leetcode.com/problems/number-of-days-in-a-month/ 
class Solution {
public:
    int numberOfDays(int Y, int M) {
        int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31 , 30, 31, 30, 31};
        if(( Y % 100 == 0 && Y % 400 == 0 )|| (Y % 100 != 0 && Y % 4 == 0) ){
            if(M == 2)
                return 29;
        }
        return m[M];
    }
};