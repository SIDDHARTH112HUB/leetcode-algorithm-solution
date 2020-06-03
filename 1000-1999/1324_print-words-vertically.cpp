//Link: https://leetcode.com/problems/print-words-vertically/ 
class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        vector<string> l;
        string tok;
        while(getline(ss, tok, ' ')) {
            l.push_back(tok);
        }
        int idx = 0;
        vector<string> ans;
        while(true) {
            string ns;
            bool f = false;
            for(auto &str : l) {
                if(idx >= str.size()) {
                    ns += ' ';
                    continue;
                    
                }
                ns += str[idx];
                f = true;
            }
            if(f == true) {
                while(ns.back() == ' ')
                    ns.pop_back();
            }else
                break;
            ans.push_back(ns);
            idx++;
        }
        return ans;
    }
};