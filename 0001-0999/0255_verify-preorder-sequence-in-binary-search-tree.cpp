//Link: https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/ 
class Solution {
public:
    int start = 0;
    bool verifyPreorder(vector<int>& preorder) {
        dfs(preorder, INT_MIN, INT_MAX);
        return start ==preorder.size();
    }
    
    void dfs(vector<int>& o, int mn, int mx) {
        if(start >= o.size() || mn > o[start] || o[start] > mx) return;
        int val = o[start++];
        dfs(o, mn, val);
        dfs(o, val, mx);
    }
};