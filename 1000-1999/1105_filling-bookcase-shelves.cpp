//Link: https://leetcode.com/problems/filling-bookcase-shelves/ 
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int m = books.size();
        int dp[m] = {0};
        for(int i = 0; i < m; ++i) {
            int w = 0;
            int h = 0;
            dp[i] = INT_MAX;
            for(int j = i; j >= 0; j--){
                if( w + books[j][0] > shelf_width)
                    break;
                w += books[j][0];
                h = max(h, books[j][1]);
                dp[i] = min(dp[i], h + (j > 0 ?dp[j-1] : 0));
            }
        }
        return dp[m-1];
    }
};