//Link: https://leetcode.com/problems/lonely-pixel-i/ 
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size(), n = picture[0].size();
        vector<int> row(m), col(n);
        vector<string> rowStr(m);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                rowStr[i] += picture[i][j];
                if(picture[i][j] == 'B') {
                    ++row[i];
                    ++col[j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};