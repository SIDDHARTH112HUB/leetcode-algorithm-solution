//Link: https://leetcode.com/problems/height-checker/ 
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto h = heights;
        sort(h.begin(), h.end());
        int ans = 0;
        for(int i = 0; i < h.size(); ++i)
            ans += h[i] == heights[i] ? 0 : 1;
        return ans;
    }
};