//Link: https://leetcode.com/problems/most-common-word/ 
class Solution {
public:
    bool isAlpha(char c) {
        return ( c>='a' && c <= 'z' ) || (c >= 'A' && c <= 'Z');
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph += ' ';
        string str;
        int mx = 0;
        string ans;
        unordered_map<string, int> m;
        unordered_set<string> banset(banned.begin(), banned.end());
        for(auto c : paragraph) {
            if(isAlpha(c)){
                if(c < 'a')
                    c += 'a' - 'A';
                str += c;
            }
            else {
                if(str.size() && banset.count(str) == 0){
                    int cnt = ++m[str];
                    if(cnt > mx) {
                        mx = cnt;
                        ans = str;
                    }
                }
                str = "";
            }
        }
        return ans;
    }
};