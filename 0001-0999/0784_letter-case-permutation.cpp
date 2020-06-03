//Link: https://leetcode.com/problems/letter-case-permutation/ 
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int size = S.length();
        vector<string> ans;
        
        for( int i = 0; i<size; i++ ){
            if( S[i] < 'A')
                continue;
            if( ans.size() == 0 )
                ans.push_back(S);
            int ans_size = ans.size();
            for( int j = 0; j<ans_size; j++){
                auto s = ans[j];
                if( s[i] > 'Z')
                    s[i] -= ('a'-'A');
                else
                    s[i] += ('a'-'A');
                ans.push_back(s);
            }
        }
        if( ans.size() == 0)
            ans.push_back(S);
        return ans;
    }
};