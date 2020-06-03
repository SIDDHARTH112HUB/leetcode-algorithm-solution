//Link: https://leetcode.com/problems/race-car/ 
class Solution {
public:
    vector<int> dp;
    int racecar(int target) {
        dp = vector<int>(target + 1);
        return dfs(target);
    }
    
    int dfs(int t){
        if(dp[t]) return dp[t];
        int n = ceil(log2(t + 1));
        if((1 << n) == t+1) return dp[t] = n;
        int res = dfs((1<<n) - t - 1 ) + n + 1;
        for(int m = 0; m < n - 1; ++m) {
            int cur = (1 << (n-1)) - (1<<m);
            res = min(res, m + n + 1 + dfs(t - cur));
        }
        dp[t] = res;
        return res;
    }
    
    
    //BFS
    int racecar1(int target) {
        set<pair<int, int> > m;
        queue<pair<int, int> > q;
        m.insert({0, 1});
        m.insert({0, -1});
        q.push({0, 1});
        int ans = 0;
        while(q.size()){
            int size = q.size();
            while(size-- >0) {
                auto t = q.front();
                q.pop();
                int p = t.first;
                int s = t.second;
                if(p == target)
                    return ans;
                int ns = s * 2;
                if(p + s < target * 2 && p + s > -target && m.count({p + s, ns}) == 0){
                    m.insert({ p+s, ns });
                    q.push({p + s, ns});
                }
                pair<int, int> np= {p, s > 0 ? -1 : 1};
                if(m.count(np) == 0){
                    m.insert(np);
                    q.push(np);
                }
            }
            ++ans;
        }
        return ans;
    }
};