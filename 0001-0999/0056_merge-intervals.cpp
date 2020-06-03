//Link: https://leetcode.com/problems/merge-intervals/ 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        vector<vector<int> > ans;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            auto &interval = intervals[i];
            if(ans.back()[1] >= interval[0]) {
                ans.back()[1] = max(interval[1], ans.back()[1]);
            }else
                ans.push_back(interval);
        }
        return ans;
    }
};