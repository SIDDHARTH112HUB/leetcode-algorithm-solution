//Link: https://leetcode.com/problems/remove-covered-intervals/ 
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int ans = 1;
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        int end = intervals[0][1];
        int start = intervals[0][0];
        for(int idx = 1; idx < intervals.size(); ++idx) {
            auto &i = intervals[idx];
            if(i[1] <= end){
                continue;
            }else {
                ++ans;
                end = i[1];
                start = i[0];
            }
        }
        return ans;
    }
};