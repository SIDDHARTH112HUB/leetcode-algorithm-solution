//Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/ 
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a > 0 || b > 0 || c > 0) {
            
            int o1 = (a & 1) | (b & 1);
            int o2 = c & 1;
            if(o1 != o2) {
                if(o2 == 0) {
                    if((a & 1) == 1)
                        ++ans;
                    if((b & 1) == 1)
                        ++ans;
                }else {
                    ++ans;
                }
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return ans;
    }
};