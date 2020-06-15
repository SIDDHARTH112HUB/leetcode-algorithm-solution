[1335.minimum-difficulty-of-a-job-schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)  

You want to schedule a list of jobs in `d` days. Jobs are dependent (i.e To work on the `i-th` job, you have to finish all the jobs `j` where `0 <= j < i`).

You have to finish **at least** one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the `d` days. The difficulty of a day is the maximum difficulty of a job done in that day.

Given an array of integers `jobDifficulty` and an integer `d`. The difficulty of the `i-th` job is `jobDifficulty[i]`.

Return _the minimum difficulty_ of a job schedule. If you cannot find a schedule for the jobs return **\-1**.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/01/16/untitled.png)

**Input:** jobDifficulty = \[6,5,4,3,2,1\], d = 2
**Output:** 7
**Explanation:** First day you can finish the first 5 jobs, total difficulty = 6.
Second day you can finish the last job, total difficulty = 1.
The difficulty of the schedule = 6 + 1 = 7 

**Example 2:**

**Input:** jobDifficulty = \[9,9,9\], d = 4
**Output:** -1
**Explanation:** If you finish a job per day you will still have a free day. you cannot find a schedule for the given jobs.

**Example 3:**

**Input:** jobDifficulty = \[1,1,1\], d = 3
**Output:** 3
**Explanation:** The schedule is one job per day. total difficulty will be 3.

**Example 4:**

**Input:** jobDifficulty = \[7,1,7,1,7,1\], d = 3
**Output:** 15

**Example 5:**

**Input:** jobDifficulty = \[11,111,22,222,33,333,44,444\], d = 6
**Output:** 843

**Constraints:**

*   `1 <= jobDifficulty.length <= 300`
*   `0 <= jobDifficulty[i] <= 1000`
*   `1 <= d <= 10`  



**Solution:**  

```cpp
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
```
      