//Link: https://leetcode.com/problems/convert-a-number-to-hexadecimal/ 
class Solution {
public:
    string toHex(int num) {
        if( num == 0 ) return "0";
        unsigned int n = (unsigned int)num;
        string ans;
        char c[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        int idx = 0;
        while(n !=0 ){
            ans += c[n%16];
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};