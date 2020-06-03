//Link: https://leetcode.com/problems/longest-repeating-character-replacement/ 

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, j = 0, mx = 0;
        unordered_map<int, int> cnt;
        for(int i = 0; i < s.size(); ++i) {
            mx = max(mx, ++cnt[s[i]]);
            while(i - j + 1 - mx > k) {
                --cnt[s[j++]];
            }
            ans = max(i - j + 1, ans);
        }
        return ans;
    }
};