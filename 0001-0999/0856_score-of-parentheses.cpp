//Link: https://leetcode.com/problems/score-of-parentheses/ 
class Solution {
public:
    int scoreOfParentheses(string S) {
        int idx = 0;
        int sum = 0;
        for( ;idx<S.size(); ){
            sum += dfs(S, idx);
        }
        return sum;
    }
    int dfs(string &s, int &idx){
        stack<int> stk;
        while(s[idx] == '('){
            stk.push(s[idx]);
            idx++;
        }
        int sum = 1;
        stk.pop();
        idx++;
        //cout<<idx<<" "<<stk.size()<<endl;
        for( ; idx<s.size(); ){
            if( s[idx] == ')'){
                
                if( stk.size() == 0 )
                    return sum;
                
                stk.pop();
                sum *=2;
                idx++;
                if( stk.size() == 0 ){
                    return sum;
                }
                
            }
            else{
                sum = sum + dfs(s, idx);
            }
        }
        return sum;
        
    }
};