//Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/ 
class Solution {
public:
    map<int, map<int, int> > mm;
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        return h(jobDifficulty, 0, d);
    }
    
    int h(vector<int>& jobDifficulty, int idx, int d) {
        if(idx >= jobDifficulty.size()) {
            return d > 0 ? 1e9 : 0;
        }
        if(d == 0) {
            return idx < jobDifficulty.size() ? 1e9 : 0;
        }
        if(mm[idx].count(d)) return mm[idx][d];
        int mx = 0;
        int res = 1e9;
        for(int i = idx; i < jobDifficulty.size(); ++i) {
            mx = max(jobDifficulty[i], mx);
            res = min(res, mx + h(jobDifficulty, i + 1, d -1));
        }
        return mm[idx][d] = res;
    }
};