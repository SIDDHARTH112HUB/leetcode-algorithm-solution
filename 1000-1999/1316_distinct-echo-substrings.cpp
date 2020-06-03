//Link: https://leetcode.com/problems/distinct-echo-substrings/ 
class Solution {
public:
    int ans = 0;
    int distinctEchoSubstrings(string text) {
        int res = 0;
        unordered_set<string> ans;
        for(int i = 1; i <= text.size()/2; ++i) {
            for(int j = 0; j <= text.size() - i; ++j) {
                auto str = text.substr(j, i);
                auto str1 = text.substr(j + i, i);
                if(ans.count(str)) continue;
                if(str.size() != str1.size()) break;
                if(str == str1){
                    ans.insert(str);
                    ++res;
                }
            }
        }
        return res;
    }
};