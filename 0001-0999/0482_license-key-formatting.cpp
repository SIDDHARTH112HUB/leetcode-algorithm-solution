//Link: https://leetcode.com/problems/license-key-formatting/ 
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int len = 0;
        for(auto c : S)
            if(c != '-')
                ++len;
        int first = len % K;
        string ans;
        for(int i = 0; i < S.size(); ++i) {
            if(S[i] == '-')continue;
            if(first == 0) {
                first = K;
                if(ans.size() > 0)
                    ans += '-';
            }
            ans += S[i] >= 'a' ? S[i] - ('a' - 'A') : S[i];
            --first;
        }
        return ans;
    }
};