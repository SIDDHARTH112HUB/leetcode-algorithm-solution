//Link: https://leetcode.com/problems/soup-servings/ 
class Solution {
public:
    double m[200][200];
    double soupServings(int N) {
        if(N > 4800) return 1;
        memset(m, 0, sizeof(m));
        N = N/25 + (N % 25 ? 1 : 0);
        return dfs(N, N);
    }
    
    double dfs(int a, int b){
        if( a <= 0 && b <= 0) return 0.5;
        if( a <= 0) return 1;
        if( b <= 0) return 0;
        if(m[a][b] > 0) return m[a][b];
        double res = 0.25 * (dfs(a - 4, b) + dfs(a-3, b-1) + dfs(a -2, b - 2) + dfs(a-1, b - 3));
        m[a][b] = res;
        return res;
    }
};