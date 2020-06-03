//Link: https://leetcode.com/problems/lonely-pixel-ii/ 
class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
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
            if(row[i] == N) {
                for(int j = 0; j < n; ++j) {
                    bool f = true;
                    if(col[j] == N && picture[i][j] == 'B') {
                        for(int k = 0; k < m; ++k) {
                            if(picture[k][j] == 'B' && rowStr[i] != rowStr[k]){
                                f = false;
                                break;
                            }
                        }
                        ans += f;
                    }
                    
                }
            }
        }
        return ans;
    }
};