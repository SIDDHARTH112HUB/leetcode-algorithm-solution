//Link: https://leetcode.com/problems/android-unlock-patterns/ 
class Solution {
public:
    int ans = 0;
    int numberOfPatterns(int m, int n) {
        set<int> v;
        dfs(0, m, n, v);
        return ans;
    }
    
    void dfs(int s, int m, int n, set<int> &v) {
        if(v.count(s)) return;
        if(m <= 0) ++ans;
        if(n <= 0) {
            return;
        }
        v.insert(s);
        for(int i = 1; i <=9; ++i) {
            if(s + i == 10 && v.count(5) == 0) continue;
            if(min(s, i) == 1 && max(s, i) == 3 && v.count(2) == 0) continue;
            if(min(s, i) == 7 && max(s, i) == 9 && v.count(8) == 0) continue;
            if(min(s, i) == 3 && max(s, i) == 9 && v.count(6) == 0) continue;
            if(min(s, i) == 1 && max(s, i) == 7 && v.count(4) == 0) continue;
            dfs(i, m - 1, n - 1, v);
        }
        v.erase(s);
    }
};