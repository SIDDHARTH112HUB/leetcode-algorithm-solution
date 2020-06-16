[826.most-profit-assigning-work](https://leetcode.com/problems/most-profit-assigning-work/)  

We have jobs: `difficulty[i]` is the difficulty of the `i`th job, and `profit[i]` is the profit of the `i`th job. 

Now we have some workers. `worker[i]` is the ability of the `i`th worker, which means that this worker can only complete a job with difficulty at most `worker[i]`. 

Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if 3 people attempt the same job that pays $1, then the total profit will be $3.  If a worker cannot complete any job, his profit is $0.

What is the most profit we can make?

**Example 1:**

  
**Input:** difficulty = \[2,4,6,8,10\], profit = \[10,20,30,40,50\], worker = \[4,5,6,7\]
  
**Output:** 100 
  
**Explanation: W**orkers are assigned jobs of difficulty \[4,4,6,6\] and they get profit of \[20,20,30,30\] seperately.

**Notes:**

*   `1 <= difficulty.length = profit.length <= 10000`
*   `1 <= worker.length <= 10000`
*   `difficulty[i], profit[i], worker[i]`  are in range `[1, 10^5]`  



**Solution:**  

```cpp
class Solution {
public:
    int maxProfitAssignment(vector<int>& D, vector<int>& P, vector<int>& W) {
        map<int, int> m;
        int ans = 0;
        for(int i=0; i<D.size(); i++ )
            m[D[i]] = max(m[D[i]], P[i]);
        for(auto it = next(m.begin()); it != m.end(); ++it)
            it->second = max( it->second, prev(it)->second );
        for(int w: W){
            auto it = m.upper_bound(w);
            ans += (it == m.begin() ? 0: prev(it)->second);
        }
        return ans;
    }
};
```
      