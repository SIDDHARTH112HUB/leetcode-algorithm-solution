//Link: https://leetcode.com/problems/valid-parentheses/ 
class Solution {
public:
    bool isValid(string s) {
        stack< char > stk;
        for( int i = 0; i<s.length(); i++){
            char c = s[i];
            if( c == '(' || c=='{' || c=='[')
                stk.push(c);
            else{
                if( stk.size() == 0 )
                    return false;
                char t = stk.top();
                if( t == '(' && c != ')')
                    return false;
                else if( t == '{' && c != '}')
                    return false;
                else if( t == '[' && c != ']')
                    return false;
                else if( t== 0 )
                    return false;
                stk.pop();
            }
        }
        return stk.size()<=0;
    }
};