//Link: https://leetcode.com/problems/longest-palindrome/ 
class Solution {
public:
    int longestPalindrome(string s) {
        map<int, int> m;
        for(auto c : s)
            ++m[c];
        int x = 0, ans = 0;
        for(auto &it : m) {
            x = max(x, it.second % 2);
            ans += it.second / 2 * 2;
        }
        return ans + x;
    }
};