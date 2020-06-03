//Link: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/ 
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int ans = 0, j = 0, i = 0;
        unordered_map<int, int> cnt;
        for(; i < s.size(); ++i) {
            ++cnt[s[i]];
            if(cnt.size() > k) {
                ans = max(ans, i - j);
                while(cnt.size() > k) {
                    if(--cnt[s[j]] == 0)
                        cnt.erase(s[j]);
                    ++j;
                }
            }
        }
        return max(ans, i - j);
    }
};