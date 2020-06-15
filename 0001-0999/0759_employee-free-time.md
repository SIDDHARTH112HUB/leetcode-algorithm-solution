[759.employee-free-time](https://leetcode.com/problems/employee-free-time/)  

We are given a list `schedule` of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping `Intervals`, and these intervals are in sorted order.

Return the list of finite intervals representing **common, positive-length free time** for _all_ employees, also in sorted order.

(Even though we are representing `Intervals` in the form `[x, y]`, the objects inside are `Intervals`, not lists or arrays. For example, `schedule[0][0].start = 1`, `schedule[0][0].end = 2`, and `schedule[0][0][0]` is not defined).  Also, we wouldn't include intervals like \[5, 5\] in our answer, as they have zero length.

**Example 1:**

**Input:** schedule = \[\[\[1,2\],\[5,6\]\],\[\[1,3\]\],\[\[4,10\]\]\]
**Output:** \[\[3,4\]\]
**Explanation:** There are a total of three employees, and all common
free time intervals would be \[-inf, 1\], \[3, 4\], \[10, inf\].
We discard any intervals that contain inf as they aren't finite.

**Example 2:**

**Input:** schedule = \[\[\[1,3\],\[6,7\]\],\[\[2,4\]\],\[\[2,5\],\[9,12\]\]\]
**Output:** \[\[5,6\],\[7,9\]\]

**Constraints:**

*   `1 <= schedule.length , schedule[i].length <= 50`
*   `0 <= schedule[i].start < schedule[i].end <= 10^8`  



**Solution:**  

```python3
# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def employeeFreeTime(self, avails):
        """
        :type avails: List[List[Interval]]
        :rtype: List[Interval]
        """
        avails_list = []
        for employee in avails:
            for avail in employee:
                avails_list.append([avail.start, avail.end])
        avails_list.sort();
        print(avails_list);
        for idx in range(1,len(avails_list)):
            cur = avails_list[idx];
            prev = avails_list[idx-1];
            if( cur[0] >=0 and prev[0]>=0 and cur[0] <= prev[1] ):
                cur[0] = prev[0];
                if( cur[1] < prev[1]):
                    cur[1] = prev[1];
                prev[0] = -1
        start = -1;
        end = -1;
        ans = []
        for avail in avails_list:
            if( avail[0] >= 0 ):
                if( start >= 0):
                    ans.append([start, avail[0]]);
                start = avail[1]
        return ans;
        #for avail in avails:
            
```
      