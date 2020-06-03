//Link: https://leetcode.com/problems/number-of-atoms/ 
class Solution {
public:
    string countOfAtoms(string formual){
        map<string, int> m;
        solve(formual, m);
        string ans;
        for( auto it : m){
            ans += it.first;
            if( it.second>1 )
                ans += to_string(it.second);
        }
        return ans;
    }
    void solve(string formula, map<string, int> &m) {
        if( formula.size() == 0 ) return ;
        if( formula[0] == ')') return;
        string str;
        if( formula[0] == '('){
            int cnt = 1;
            map<string, int> nest_m;
            solve(formula.substr(1), nest_m);
            int i = 1;
            while( cnt > 0 ){
                if( formula[i]=='(')
                    cnt++;
                else if( formula[i] == ')')
                    cnt--;
                i++;
            }
            int num = 0;
            while( i < formula.size() && formula[i]>='0' && formula[i]<='9')
                num = num * 10 + formula[i++]-'0';
            num = num?num:1;
            for( auto it:nest_m){
                it.second *= num;
                m[it.first]+= it.second;
            }
            solve(formula.substr(i), m);
        }else{
            string key ="";
            key+=formula[0];
            int i = 1;
            while( i < formula.size() && formula[i]>='a' && formula[i]<='z')
                key+= formula[i++];
            int num = 0;
            while( i < formula.size() && formula[i]>='0' && formula[i]<='9')
                num = num * 10 + (formula[i++]-'0');
            m[key] += (num?num:1);
            solve(formula.substr(i), m);
        }
    }
};