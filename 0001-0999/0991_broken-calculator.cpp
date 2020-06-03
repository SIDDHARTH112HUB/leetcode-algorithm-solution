//Link: https://leetcode.com/problems/broken-calculator/ 
class Solution {
public:
    int ans = 0;
    int brokenCalc(int X, int Y) {
        if( X >= Y ) return X-Y + ans;
        ++ans;
        if( Y % 2 == 0 )
            return brokenCalc(X, Y/2);
        else{
            ++ans;
            return brokenCalc(X, (Y+1)/2);
        }
    }
};