//Link: https://leetcode.com/problems/insert-interval/ 
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int cur = 0;
        int n = intervals.size();
        vector<Interval> ans;
        while( cur < n && intervals[cur].end < newInterval.start )
            ans.push_back(intervals[cur++]);
        while( cur < n && intervals[cur].start <= newInterval.end){
            newInterval.start = min(intervals[cur].start, newInterval.start);
            newInterval.end = max(intervals[cur].end, newInterval.end);
            ++cur;
        }
        ans.push_back(newInterval);
        while( cur < n )
            ans.push_back( intervals[cur++]);
        return ans;
    }
};