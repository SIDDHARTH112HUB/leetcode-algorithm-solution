//Link: https://leetcode.com/problems/minimum-number-of-frogs-croaking/ 
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int ans = 0;
        for(auto ch : croakOfFrogs) {
            if(ch == 'c'){
                ++c;
            }else if( ch == 'r') {
                if(c <= 0)
                    return -1;
                --c;
                ++r;
            }else if(ch == 'o') {
                if(r <= 0)
                    return -1;
                --r;
                ++o;
            }else if(ch == 'a') {
                if(o <=0) return -1;
                --o;
                ++a;
            }else if(ch == 'k') {
                if(a <= 0) return -1;
                --a;
            }
            ans = max(ans, c + r + o + a);
        }
        if(c > 0 || r > 0 || o > 0 || a > 0) return -1;
        return ans;
    }
};