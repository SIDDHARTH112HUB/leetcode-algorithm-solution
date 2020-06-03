//Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/ 
class Solution {
public:
    map<int, int > m;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int> > v;
        for(int i = 0; i < startTime.size(); ++i) {
            int s = startTime[i];
            int e = endTime[i];
            int p = profit[i];
            v.push_back({s, e, p});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            //if(a[0] == b[0]) return a[1] < b[1];
            return a[1] < b[1];
        });
        vector<int> dp(v.size());
        
        //dp[0] = v[0][2];
        //m[v[0][1]] = dp[0];
        for(int i = 0; i < v.size(); ++i) {
            int e = v[i][1];
            int s = v[i][0];
            auto it = m.upper_bound(s);
            if(it == m.begin()) it =m.end();
            else --it;
            dp[i] = max( (i > 0 ? dp[i-1] : 0), (it != m.end() ? it->second : 0) + v[i][2]);
            m[e] = max(m[e], dp[i]);
        }
        return dp[v.size() -1];
        //return dfs(v, 1, v[0][1]) + v[0][2];
    }
    /*
    int dfs(vector<vector<int> > &v, int idx, int e) {
        if(idx >= v.size()) return 0;
        auto it = m.lower_bound(e);
        //if(it != m.end()) return it->second;
        if(m.count(e)) return m[idx];
        int res = 0;
        for(int i = idx; i < v.size(); ++i) {
            if(v[i][0] >= e) {
                //while(j < v.size() && v[j][0] < v[i][1] ) ++j;
                res = max(res, dfs(v, i, v[i][1] ) + v[i][2]);
            }
        }
        m[e] =res;
        return res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int> > v;
        for(int i = 0; i < startTime.size(); ++i) {
            int s = startTime[i];
            int e = endTime[i];
            int p = profit[i];
            v.push_back({e, s, p});
        }
        sort(v.begin(), v.end());
        int i = 0, ans = 0;
        while(i < v.size()) {
            int e = v[i][0];
            int mx = v[i][2];
            ++i;
            while(i < v.size() && e > v[i][1]) {
                mx = max(mx, v[i][2]);
                ++i;
            }
            ans += mx;
        }
        return ans;
    }*/
};