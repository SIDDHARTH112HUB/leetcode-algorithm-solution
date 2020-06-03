//Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/ 
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int ans = 0;
        for(auto n : arr) {
            int prev = n - difference;
            m[n] = m[prev] + 1;
            ans = max(ans, m[n]);
        }
        return ans;
    }
};