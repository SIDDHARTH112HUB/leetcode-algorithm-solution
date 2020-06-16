[77.combinations](https://leetcode.com/problems/combinations/)  

Given two integers _n_ and _k_, return all possible combinations of _k_ numbers out of 1 ... _n_.

**Example:**

  
**Input:** n = 4, k = 2
  
**Output:**
  
\[
  
  \[2,4\],
  
  \[3,4\],
  
  \[2,3\],
  
  \[1,2\],
  
  \[1,3\],
  
  \[1,4\],
  
\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combine(int n, int k) {
        if( k == 0 ) return {{}};
        vector<int> item;
        dfs(n, k, 1, item);
        return ans;
    }
    void dfs(int n, int k, int num, vector<int> &item){
        if( k == 0 ){
            ans.push_back(item);
            return;
        }
        if( num > n ) return;
        item.push_back(num);
        dfs(n, k-1, num+1, item);
        item.pop_back();
        
        dfs(n, k, num+1, item);
    }
};
```
      