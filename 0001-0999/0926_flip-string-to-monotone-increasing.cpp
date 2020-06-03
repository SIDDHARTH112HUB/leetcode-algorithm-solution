//Link: https://leetcode.com/problems/flip-string-to-monotone-increasing/ 
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int result = 0, ones=0;
        for( auto &c : S){
            if( c== '0')
                result = min(result+1, ones);
            else
                ++ones;
        }
        return result;
    }
};