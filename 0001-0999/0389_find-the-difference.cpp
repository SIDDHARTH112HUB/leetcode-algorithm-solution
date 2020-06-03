//Link: https://leetcode.com/problems/find-the-difference/ 
class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[128] = {0};
        for(auto c : s)
            ++cnt[c];
        for(auto c : t)
            if(--cnt[c] < 0)
                return c;
        return 0;
    }
};