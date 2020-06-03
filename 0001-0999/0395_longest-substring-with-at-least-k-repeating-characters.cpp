//Link: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/ 
class Solution {
public:
    int longestSubstring(string s, int k) {
        if( s.size() < k ) return 0;
        int mxIdx = 0, n = s.size(), res = 0;
        int cnt[128] = {0};
        for(auto c : s)
            ++cnt[c];
        bool ok = true;
        for(int i = 0; i < s.size(); ++i) {
            if(cnt[s[i]] < k) {
                res = max(res, longestSubstring(s.substr(mxIdx, i - mxIdx), k));
                ok = false;
                mxIdx = i + 1;
            }
        }
        return ok ? n : max(res, longestSubstring(s.substr(mxIdx, n - mxIdx), k));
    }
};