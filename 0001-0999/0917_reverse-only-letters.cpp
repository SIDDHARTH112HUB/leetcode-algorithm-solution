//Link: https://leetcode.com/problems/reverse-only-letters/ 
class Solution {
public:
    bool isLetter(char c){
        return (c>='A' && c<='Z') || ( c>='a' && c<='z');
    }
    string reverseOnlyLetters(string S) {
        string ans = S;
        int j = S.size()-1;
        for( int i = 0; i<S.size(); i++ ){
            char c = S[i];
            if( isLetter(c) ){
                while( !isLetter(S[j])){
                   j--;
                }
                ans[i] = S[j];
                j--;
            }else{
                continue;
            }
        }
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};