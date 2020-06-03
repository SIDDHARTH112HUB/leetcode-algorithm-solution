//Link: https://leetcode.com/problems/find-right-interval/ 
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        for(int i = 0; i < intervals.size(); ++i) {
            auto &inter = intervals[i];
            if(m.count(inter[0]) == 0)
                m[inter[0]] = i;
        }
        vector<int> ans;
        for(auto &inter : intervals) {
            auto it = m.lower_bound(inter[1]);
            if(it != m.end())
                ans.push_back(it->second);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};