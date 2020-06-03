//Link: https://leetcode.com/problems/brace-expansion/ 
class Solution {
public:
    vector<string> ans;
    vector<string> permute(string S) {
        vector<vector<char> > chars;
        for(int i = 0; i < S.size(); i++) {
            char ch = S[i];
            if(ch == '{'){
                chars.push_back({});
                int j = i+1;
                for(; j<S.size(); j+=2){
                    chars.back().push_back(S[j]);
                    if(S[j+1] == '}'){
                        break;
                    }
                }
                i = j+1;
            }else{
                chars.push_back({ch});
            }
        }
        string str;
        dfs(chars, 0, str);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void dfs(vector<vector<char> > chars, int idx, string &str) {
        if(idx == chars.size()){
            ans.push_back(str);
            return;
        }
        for(auto c : chars[idx]){
            str.push_back(c);
            dfs(chars, idx+1, str);
            str.pop_back();
        }
    }
};