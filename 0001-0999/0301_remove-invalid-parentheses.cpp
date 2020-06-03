//Link: https://leetcode.com/problems/remove-invalid-parentheses/ 
class Solution {
public:
    
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        vector<string> ans;
        unordered_set<string> v;
        v.insert(s);
        bool found = false;
        while( q.size() ){
            int size = q.size();
            while( size-- > 0 ){
                auto t = q.front(); q.pop();
                if( isValid(t) ){
                    ans.push_back(t);
                    found = true;
                }
                if( found ) continue;
                for( int i = 0; i< t.size(); i++){
                    if( t[i] != '(' && t[i] != ')') continue;
                    string str = t.substr(0, i) + t.substr(i+1);
                    if( v.count(str ) == 0 ){
                        q.push(str);
                        v.insert(str);
                    }
                }
            }
        }
        return ans;
    }
    
    bool isValid(string &s){
        int cnt = 0;
        for( char c : s){
            if( c == '(')
                ++cnt;
            else if( c == ')')
                --cnt;
            if( cnt < 0 ) return false;
        }
        return cnt == 0;
    }
    
};