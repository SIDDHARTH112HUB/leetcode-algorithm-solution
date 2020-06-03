//Link: https://leetcode.com/problems/longest-chunked-palindrome-decomposition/ 
class Solution {
public:
    int ans = 0;
    int longestDecomposition(string text) {
        dfs(text, 0, text.size());
        return ans;
    }
    
    void dfs(string &text, int i, int j) {
        if(i >= j) return;
        for(int k = 1; k <= j - i - k; ++k) {
            if(text.substr(i, k) == text.substr(j - k, k)){
                ans += 2;
                return dfs(text, i + k, j - k);
            }
        }
        ++ans;
    }
};