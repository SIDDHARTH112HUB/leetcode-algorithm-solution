[57.insert-interval](https://leetcode.com/problems/insert-interval/)  

Given a set of _non-overlapping_ intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

**Example 1:**

  
**Input:** intervals = \[\[1,3\],\[6,9\]\], newInterval = \[2,5\]
  
**Output:** \[\[1,5\],\[6,9\]\]
  

**Example 2:**

  
**Input:** intervals = `[[1,2],[3,5],[6,7],[8,10],[12,16]]`, newInterval = `[4,8]`
  
**Output:** \[\[1,2\],\[3,10\],\[12,16\]\]
  
**Explanation:** Because the new interval `[4,8]` overlaps with `[3,5],[6,7],[8,10]`.

**NOTE:** input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.  



**Solution:**  

```cpp
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
```
      