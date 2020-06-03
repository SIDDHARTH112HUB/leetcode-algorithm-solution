//Link: https://leetcode.com/problems/string-compression/ 
class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1, j = 0;
        for(int i = 0; i <= chars.size(); ++i) {
            if(i == 0 || i == chars.size() || chars[i] != chars[i-1]) {
                if(cnt > 1) {
                    string str = to_string(cnt);
                    for(auto c : str) {
                        chars[j++] = c;
                    }
                }
                if(i == chars.size()) return j;
                cnt = 1;
                chars[j++] = chars[i];
            }else{
                ++cnt;
            }
        }
        return j;
    }
};
