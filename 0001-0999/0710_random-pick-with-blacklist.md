[710.random-pick-with-blacklist](https://leetcode.com/problems/random-pick-with-blacklist/)  

Given a blacklist `B` containing unique integers from `[0, N)`, write a function to return a uniform random integer from `[0, N)` which is **NOT** in `B`.

Optimize it such that it minimizes the call to system’s `Math.random()`.

**Note:**

1.  `1 <= N <= 1000000000`
2.  `0 <= B.length < min(100000, N)`
3.  `[0, N)` does NOT include N. See [interval notation](https://en.wikipedia.org/wiki/Interval_(mathematics)).

**Example 1:**

  
**Input:** \["Solution","pick","pick","pick"\] \[\[1,\[\]\],\[\],\[\],\[\]\]
  
**Output:** \[null,0,0,0\]
  

**Example 2:**

  
**Input:** \["Solution","pick","pick","pick"\] \[\[2,\[\]\],\[\],\[\],\[\]\]
  
**Output:** \[null,1,1,1\]
  

**Example 3:**

  
**Input:** \["Solution","pick","pick","pick"\] \[\[3,\[1\]\],\[\],\[\],\[\]\]
  
**Output:** \[null,0,0,2\]
  

**Example 4:**

  
**Input:** \["Solution","pick","pick","pick"\] \[\[4,\[2\]\],\[\],\[\],\[\]\]
  
**Output:** \[null,1,3,1\]
  

**Explanation of Input Syntax:**

The input is two lists: the subroutines called and their arguments. `Solution`'s constructor has two arguments, `N` and the blacklist `B`. `pick` has no arguments. Arguments are always wrapped with a list, even if there aren't any.  



**Solution:**  

```cpp
class Solution {
public:
    vector<pair<int, int> > interval;
    int n = 0;
    Solution(int N, vector<int> blacklist) {
        int size = blacklist.size();
        n = N;
        if( size == 0 ) return;
        size += 1;
        blacklist.push_back(N);
        sort(blacklist.begin(), blacklist.end());
        
        if(blacklist[0] > 0) interval.push_back({ 0,  blacklist[0]});
        for( int i = 1; i<size; i++ ){
            if(blacklist[i] > blacklist[i-1] + 1) {
                interval.push_back({blacklist[i-1]+1, blacklist[i]});
            }
        }
    }
    
    int pick() {
        if(interval.size() == 0)
            return rand() % n;
        int r = rand();
        int idx = r % interval.size();
        return r % (interval[idx].second - interval[idx].first) + interval[idx].first;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
```
      