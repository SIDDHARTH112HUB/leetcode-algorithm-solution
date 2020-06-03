//Link: https://leetcode.com/problems/longest-palindromic-substring/ 
class Solution {
public:
    string longestPalindrome(string s) {
        string str = "$#";
        for(int i = 0; i < s.size(); ++i) {
            str += s[i];
            str += '#';
        }
        str += '@';
        vector<int> len(str.size(), 1);
        int i = 1, mx = 0, id = 1;
        while(i < str.size() - 1) {
            len[i] = mx > i ? min(len[2 * id - i], mx - i) : 1;
            while(str[i + len[i]] == str[i - len[i]])
                ++len[i];
            if(len[i] + i> mx) {
                id = i;
                mx = len[i] + i;
            }
            ++i;
        }
        int idx = max_element(len.begin(), len.end()) - len.begin();
        string ans;
        for(int i = idx - len[idx] + 1; i < idx + len[idx]; ++i) {
            char c = str[i];
            if(c != '#' && c != '$' && c != '@')
                ans += c;
        }
        return ans;
    }
};