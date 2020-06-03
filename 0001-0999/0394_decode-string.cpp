//Link: https://leetcode.com/problems/decode-string/ 
class Solution {
public:
    int idx = 0;
    string decodeString(string s) {
        string ans;
        int num = 0;
        while(idx < s.size()) {
            char c = s[idx];
            if(c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            }else if(c == '['){
                ++idx;
                auto str = decodeString(s);
                while(num > 0){
                    --num;
                    ans += str;
                }
            }else if(c == ']'){
                return ans;
            }else {
                ans += c;
            }
            ++idx;
        }
        return ans;
    }
};