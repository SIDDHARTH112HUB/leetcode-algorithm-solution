//Link: https://leetcode.com/problems/generate-parentheses/ 
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(s, 0, n);
        return ans;
    }
    void dfs(string &s, int l, int r){
        if( l == r && r==0){
            ans.push_back(s);
            return;
        }
        
        if( l<r ){
            s += "(";
            dfs(s, l+1, r);
            s.pop_back();
        }
        if( l>0 ){
            s+= ")";
            dfs(s, l-1, r-1);
            s.pop_back();
        }

    }
};