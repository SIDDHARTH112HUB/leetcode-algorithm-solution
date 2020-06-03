//Link: https://leetcode.com/problems/longest-absolute-file-path/ 
class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        string tok;
        vector<string> stk;
        int ans = 0;
        while(getline(ss, tok, '\n')) {
            int i = 0;
            while(tok[i] == '\t') ++i;
            while(stk.size() >  i) stk.pop_back();
            //cout<<tok<<" "<<i<<endl;
            tok = tok.substr(i);
            
            if(tok.find('.') != string::npos) {
                //cout<<"get"<<endl;
                int n = 0;
                for(auto s : stk)
                    n += s.size() + 1;
                n += tok.size();
                if(n > ans) ans = n;
            }else
                stk.push_back(tok);
        }
        return ans;
    }
};