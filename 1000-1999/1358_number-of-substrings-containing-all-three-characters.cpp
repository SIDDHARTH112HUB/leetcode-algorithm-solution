//Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/ 
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, st = 0, e = 0, go = 0;
        vector<int> cnt(3);
        while(e < s.size()) {
            if(cnt[s[e++] - 'a']++ == 0) go++;
            int prev = st;
            while(go >= 3 ) {
                if(cnt[s[st++] - 'a']-- == 1) --go;
            }
            ans += (st - prev) * (s.size() - e+ 1);
        }
        return ans;
    }
};