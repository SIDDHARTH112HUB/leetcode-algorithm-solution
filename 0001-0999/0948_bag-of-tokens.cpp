//Link: https://leetcode.com/problems/bag-of-tokens/ 
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        int ans = 0;
        int cur = 0;
        int l = 0, r = tokens.size()-1;
        while( l <= r ){
            int t = tokens[l];
            if( P < t ){
                if( cur == 0 )
                    return ans;
                cur--;
                P += tokens[r--];
                continue;
            }
            P -= t;
            cur++;
            ans = max(ans, cur);
            l++;
        }
        return ans;
    }
};