//Link: https://leetcode.com/problems/count-different-palindromic-subsequences/ 
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > memo;
    int M = 1e+9+7;
    int countPalindromicSubsequences(string S) {
        return dfs(S, 0, S.size()-1);
    }
    
    int dfs(string &s, int i , int j){
        if(i > j) return 0;
        if(i == j) return 1;
        if(memo[i].count(j)) return memo[i][j];
        int res = 0;
        if(s[i] != s[j]) {
            res = ((dfs(s, i+1, j) + dfs(s, i, j-1))%M + (M - dfs(s, i +1, j - 1))%M) %M;
        }else{
            int a = i + 1, b = j -1;
            while(a < j && s[i] != s[a])
                ++a;
            while(b > i && s[i] != s[b])
                --b;
            if(b > a) {
                res = (dfs(s, i+1, j-1) * 2)%M  + (M- dfs(s, a+1, b-1))%M;
            }else{
                res = (dfs(s, i+1, j-1) * 2 ) %M + (b == a ? 1 : 2);
            }
        
        }
        memo[i][j] = res %M;
        return res %M;
    }
};