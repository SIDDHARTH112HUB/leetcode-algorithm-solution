[254.factor-combinations](https://leetcode.com/problems/factor-combinations/)  

Numbers can be regarded as product of its factors. For example,

  
8 = 2 x 2 x 2;
  
  = 2 x 4.
  

Write a function that takes an integer _n_ and return all possible combinations of its factors.

**Note:**

1.  You may assume that _n_ is always positive.
2.  Factors should be greater than 1 and less than _n_.

**Example 1:**

  
**Input:** `1`
  
**Output:** \[\]
  

**Example 2:**

  
**Input:** `37`
  
**Output:**\[\]

**Example 3:**

  
**Input:** `12`
  
**Output:**
  
\[
  
  \[2, 6\],
  
  \[2, 2, 3\],
  
  \[3, 4\]
  
\]

**Example 4:**

  
**Input:** `32`
  
**Output:**
  
\[
  
  \[2, 16\],
  
  \[2, 2, 8\],
  
  \[2, 2, 2, 4\],
  
  \[2, 2, 2, 2, 2\],
  
  \[2, 4, 4\],
  
  \[4, 8\]
  
\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> getFactors(int n) {
        vector<int> item;
        dfs(n, 2, item);
        return ans;
    }
    
    void dfs(int n, int start, vector<int> &item) {
        for(int i = start; i * i <= n; ++i) {
            if(n % i == 0) {
                if(n / i < i) continue;
                item.push_back(i);
                item.push_back(n / i);
                ans.push_back(item);
                item.pop_back(); item.pop_back();
                item.push_back(i);
                dfs(n / i, i, item);
                item.pop_back();
            }
        }
    }
};
```
      