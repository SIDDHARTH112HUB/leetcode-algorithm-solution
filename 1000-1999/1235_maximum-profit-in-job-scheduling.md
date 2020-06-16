[1235.maximum-profit-in-job-scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)  

We have `n` jobs, where every job is scheduled to be done from `startTime[i]` to `endTime[i]`, obtaining a profit of `profit[i]`.

You're given the `startTime` , `endTime` and `profit` arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with overlapping time range.

If you choose a job that ends at time `X` you will be able to start another job that starts at time `X`.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/10/10/sample1_1584.png)**

  
**Input:** startTime = \[1,2,3,3\], endTime = \[3,4,5,6\], profit = \[50,10,40,70\]  
**Output:** 120  
**Explanation:** The subset chosen is the first and fourth job.   
Time range \[1-3\]+\[3-6\] , we get profit of 120 = 50 + 70.  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/10/10/sample22_1584.png)**

  
 **Input:** startTime = \[1,2,3,4,6\], endTime = \[3,5,10,6,9\], profit = \[20,20,100,70,60\]  
**Output:** 150  
**Explanation:** The subset chosen is the first, fourth and fifth job.   
Profit obtained 150 = 20 + 70 + 60.  

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/10/10/sample3_1584.png)**

  
**Input:** startTime = \[1,1,1\], endTime = \[2,3,4\], profit = \[5,6,4\]  
**Output:** 6  

**Constraints:**

*   `1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4`
*   `1 <= startTime[i] < endTime[i] <= 10^9`
*   `1 <= profit[i] <= 10^4`  



**Solution:**  

```cpp
class Solution {
public:
    map<int, int > m;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        vector<vector<int> > v;
        for(int i = 0; i < startTime.size(); ++i) {
            int s = startTime[i];
            int e = endTime[i];
            int p = profit[i];
            v.push_back({s, e, p});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            //if(a[0] == b[0]) return a[1] < b[1];
            return a[1] < b[1];
        });
        vector<int> dp(v.size());
        
        //dp[0] = v[0][2];
        //m[v[0][1]] = dp[0];
        for(int i = 0; i < v.size(); ++i) {
            int e = v[i][1];
            int s = v[i][0];
            auto it = m.upper_bound(s);
            if(it == m.begin()) it =m.end();
            else --it;
            dp[i] = max( (i > 0 ? dp[i-1] : 0), (it != m.end() ? it->second : 0) + v[i][2]);
            m[e] = max(m[e], dp[i]);
        }
        return dp[v.size() -1];
        //return dfs(v, 1, v[0][1]) + v[0][2];
    }
    /*
    int dfs(vector<vector<int> > &v, int idx, int e) {
        if(idx >= v.size()) return 0;
        auto it = m.lower_bound(e);
        //if(it != m.end()) return it->second;
        if(m.count(e)) return m[idx];
        int res = 0;
        for(int i = idx; i < v.size(); ++i) {
            if(v[i][0] >= e) {
                //while(j < v.size() && v[j][0] < v[i][1] ) ++j;
                res = max(res, dfs(v, i, v[i][1] ) + v[i][2]);
            }
        }
        m[e] =res;
        return res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int> > v;
        for(int i = 0; i < startTime.size(); ++i) {
            int s = startTime[i];
            int e = endTime[i];
            int p = profit[i];
            v.push_back({e, s, p});
        }
        sort(v.begin(), v.end());
        int i = 0, ans = 0;
        while(i < v.size()) {
            int e = v[i][0];
            int mx = v[i][2];
            ++i;
            while(i < v.size() && e > v[i][1]) {
                mx = max(mx, v[i][2]);
                ++i;
            }
            ans += mx;
        }
        return ans;
    }*/
};
```
      