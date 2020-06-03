//Link: https://leetcode.com/problems/remove-comments/ 
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool inblock = false;
        vector<string> ans;
        string res;
        for(auto &line : source) {
            for(int i = 0; i < line.size(); ++i) {
                if(!inblock) {
                    auto t = line.substr(i, 2);
                    if(t == "/*") { inblock = true; ++i; continue;}
                    else if(t == "//") {break;}
                    res += line[i];
                }else {
                    if(line.substr(i, 2) == "*/") {
                        inblock = false;
                        ++i;
                    }
                }
            }
            if(res.size() > 0 && !inblock) {
                ans.push_back(res);
                res = "";
            }
        }
        
        return ans;
    }
};