//Link: https://leetcode.com/problems/non-overlapping-intervals/ 
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        int prev = INT_MIN;
        int ans = 0;
        for(auto &it: intervals) {
            if(it[0] >= prev) {
                prev = it[1];
            }else
                ++ans;
        }
        return ans;
    }
};