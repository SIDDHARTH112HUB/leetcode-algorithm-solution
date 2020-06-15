[1215.stepping-numbers](https://leetcode.com/problems/stepping-numbers/)  

A _Stepping Number_ is an integer such that all of its adjacent digits have an absolute difference of exactly `1`. For example, `321` is a Stepping Number while `421` is not.

Given two integers `low` and `high`, find and return a **sorted** list of all the Stepping Numbers in the range `[low, high]` inclusive.

**Example 1:**

**Input:** low = 0, high = 21
**Output:** \[0,1,2,3,4,5,6,7,8,9,10,12,21\]

**Constraints:**

*   `0 <= low <= high <= 2 * 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> ans;
    vector<int> countSteppingNumbers(int low, int high) {
        for(int i = 0; i <= 9; ++i) {
            helper(low, high, i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void helper(long long low, long long high, long long target) {
        queue<long long> q;
        q.push(target);
        while(q.size()) {
            long long num = q.front();
            q.pop();
            if(num >= low && num <= high)
                ans.push_back(num);
            if(num == 0 || num >= high) continue;
            long long mod = num % 10;
            long long n1 = num * 10 + (mod + 1);
            long long n2 = num * 10 + (mod - 1);
            if(mod != 0) 
                q.push(n2);
            if(mod != 9)
                q.push(n1);
        }
    }
};
```
      