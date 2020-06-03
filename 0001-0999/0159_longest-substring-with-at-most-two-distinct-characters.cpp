//Link: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/ 
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int j = 0, i = 0, ans = 0;
        map<int, int> m;
        for(; i < s.size(); ++i) {
            ++m[s[i]];
            if(m.size() > 2) {
                ans = max(ans, i - j);
                while(j < i && m.size() >2) {
                    --m[s[j]];
                    if(m[s[j]] == 0)
                        m.erase(s[j]);
                    ++j;
                }
            }
        }
        ans = max(ans, i - j);
        return ans;
    }
};