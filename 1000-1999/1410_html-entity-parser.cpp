//Link: https://leetcode.com/problems/html-entity-parser/ 
class Solution {
public:
    string entityParser(string text) {
        map<string, char> m;
        m["&quot;"] = '\"';
        m["&apos;"] = '\'';
        m["&amp;"] = '&';
        m["&gt;"] = '>';
        m["&lt;"] = '<';
        m["&frasl;"] = '/';
        string ans;
        int i = 0;
        while(i < text.size()) {
            char c = text[i];
            ++i;
            if(c != '&') {
                ans += c;
                continue;
            }
            bool f = false;
            for(int a = 4; a <= 7; ++a) {
                string sub = text.substr(i - 1, a);
                if(m.count(sub)) {
                    ans += m[sub];
                    i += a - 1;
                    f = true;
                    break;
                }
            }
            if(!f)
                ans += c;
        }
        return ans;
    }
};