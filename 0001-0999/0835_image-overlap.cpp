//Link: https://leetcode.com/problems/image-overlap/ 
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ans = 0;
        for(int i = 0; i < A.size(); ++i){
            for(int j = 0; j < A[0].size(); ++j){
                ans = max(ans, helper(A, B, i, j));
                ans = max(ans, helper(B, A, i, j));
            }
        }
        return ans;
    }
    
    int helper(vector<vector<int>>& A, vector<vector<int>>& B, int x, int y) {
        int sy = y, ans = 0;
        for(int i = 0; x < A.size(); ++i){
            y = sy;
            for(int j = 0; y < A[0].size(); ++j) {
                if(A[i][j] == B[x][y] && B[x][y] == 1)
                    ++ans;
                ++y;
            }
            ++x;
        }
        return ans;
    }
};