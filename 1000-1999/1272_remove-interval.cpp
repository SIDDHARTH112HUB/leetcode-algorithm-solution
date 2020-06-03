//Link: https://leetcode.com/problems/remove-interval/ 
class Solution {
public:
    int c = 10000000;
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        map<int, int> m;
        vector<vector<int> > res;
        m[toBeRemoved[0]] += c;
        m[toBeRemoved[1]] -= c;
        for(auto &inter : intervals) {
            int a = inter[0], b = inter[1];
            ++m[a];
            --m[b];
        }
        int prev = -1;
        int cnt;
        for(auto &it : m) {
            int a = it.first;
            cnt += it.second;
            if(cnt == 1) {
                prev = a;
            }else if(cnt > 1) {
                if(cnt >= c) {
                    if(prev != -1) {
                        res.push_back({prev, a});
                    }
                }
                prev = -1;
            }else{
                if(prev != -1) {
                    res.push_back({prev, a});
                }
                prev = -1;
            }
        }
        return res;
    }
};