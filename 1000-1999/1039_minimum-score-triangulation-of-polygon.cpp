//Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int > > m;
    int minScoreTriangulation(vector<int>& A) {
        return dfs(A, 0, A.size()-1);
    }
    
    
    int dfs(vector<int> &A, int i, int j) {
        if(m[i].count(j)) return m[i][j];
        if(j - i < 2) return 0;
        int res = INT_MAX;
        for(int k = i + 1; k <j; k++){
            res = min(res, dfs(A, i, k) + dfs(A, k, j) + A[i] * A[k] * A[j]);
        }
        m[i][j] = res;
        return res;
    }
};