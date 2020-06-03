//Link: https://leetcode.com/problems/ambiguous-coordinates/ 
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        int n = S.size();
        vector<string> ans;
        for( int i = 1; i < n-2; i++){
            vector<string> A = helper(S.substr(1,i)), B = helper(S.substr(i+1, n-i-2));
            for( auto &a : A){
                for( auto &b : B){
                    ans.push_back("("+a+", "+b+")");
                }
            }
        }
        return ans;
    }
    
    vector<string> helper(string S){
        int n = S.size();
        if( n == 0 || (n > 1 && S[0] == '0' && S[n-1] == '0') ) return {};
        if( n > 1 && S[0] == '0') return {"0."+ S.substr(1)};
        if( n == 1 ) return {S};
        if( n > 1 && S[n-1] == '0') return {S};
        vector<string> ans;
        ans.push_back(S);
        for( int i = 1; i < n; i++){
            ans.push_back(S.substr(0,i)+"."+S.substr(i));
            
        }
        return ans;
    }
};