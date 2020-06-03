//Link: https://leetcode.com/problems/count-binary-substrings/ 
class Solution {
public:
    int countBinarySubstrings(string s) {
        int sum = 0, ans = 0;
        int z = 0, o = 0;
        for(int i = 0; i < s.size(); ++i) {
            if(i > 0 && s[i] != s[i-1]) {
               if(s[i] == '1') o = 0;
                else z = 0;
            }
            if(s[i] == '1') {
                ++o;
                ans += o <= z;
            }else {
                z++;
                ans += z <= o;
            }
        }
        return ans;
    }
};
