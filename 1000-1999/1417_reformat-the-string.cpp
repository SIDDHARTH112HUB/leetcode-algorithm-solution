//Link: https://leetcode.com/problems/reformat-the-string/ 
class Solution {
public:
    string reformat(string s) {
        string l, d;
        for(auto c : s) {
            if(c>='0' && c<='9')
                d+= c;
            else
                l += c;
        }
        string ans;
        if(abs(int(l.size()) - int(d.size())) > 1)
            return "";
        string s1, s2;
        if(l.size() > d.size()) {
            s1 = l;
            s2 = d;
        }else{
            s1 = d;
            s2 = l;
        }
        while(s1.size()) {
            ans += s1.back();
            s1.pop_back();
            if(s2.size()){
                ans += s2.back();
                s2.pop_back();
            }
        }
        return ans;
    }
};