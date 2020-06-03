//Link: https://leetcode.com/problems/di-string-match/ 
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int mx = S.size();
        int mn = 0;
        vector<int> ans;
        for( int i = 0; i<S.size(); i++ ){
            if( S[i] == 'I'){
                ans.push_back(mn++);
            }else{
                ans.push_back(mx--);
            }
        }
        if( S.back() == 'I')
            ans.push_back(mn);
        else
            ans.push_back(mx);
        return ans;
    }
};