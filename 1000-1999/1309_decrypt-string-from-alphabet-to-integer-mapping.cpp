//Link: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/ 
class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        s+= ".......";
        for(int i = 0; i < s.size() - 3; ++i) {
            if(s[i] == '.') break;
            int n = 0;
            if(s[i+2] == '#'){
                n = stoi(s.substr(i, 2)) - 1;
                i += 2;
            }else {
                n = s[i]-'0' - 1;
            }
            ans += 'a' + n;
        }
        return ans;
    }
};