//Link: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/ 
class Solution {
public:
    int mnx = INT_MAX;
    int mny = INT_MAX;
    int mxx = 0;
    int mxy = 0;
    int minArea(vector<vector<char>>& image, int x, int y) {
        dfs(image, x, y);
        return (mxx - mnx+1) * (mxy - mny+1);
    }
    
    void dfs(vector<vector<char>>& image, int x, int y) {
        int m = image.size(), n = image[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || image[x][y] == '0') return;
        mnx = min(x, mnx); mny = min(y, mny);
        mxx = max(x, mxx); mxy = max(y, mxy);
        image[x][y] = '0';
        dfs(image, x + 1, y);
        dfs(image, x, y + 1);
        dfs(image, x, y - 1);
        dfs(image, x - 1, y);
    }
};