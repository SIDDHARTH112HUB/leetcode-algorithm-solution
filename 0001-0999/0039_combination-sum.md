[39.combination-sum](https://leetcode.com/problems/combination-sum/)  

Given a **set** of candidate numbers (`candidates`) **(without duplicates)** and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

The **same** repeated number may be chosen from `candidates` unlimited number of times.

**Note:**

*   All numbers (including `target`) will be positive integers.
*   The solution set must not contain duplicate combinations.

**Example 1:**

**Input:** candidates = `[2,3,6,7],` target = `7`,
**A solution set is:**
\[
  \[7\],
  \[2,2,3\]
\]

**Example 2:**

**Input:** candidates = \[2,3,5\]`,` target = 8,
**A solution set is:**
\[
  \[2,2,2,2\],
  \[2,3,3\],
  \[3,5\]
\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //if( candidates.size() =--
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, item);
        return ans;
    }
    void dfs(vector<int> &nums, int target, int idx, vector<int> &item){
        if( target == 0 ){
            ans.push_back(item);
            return;
        }
        if( target<0)
            return;
        if( idx >= nums.size() )
            return;
        
        int n = nums[idx];
        if( target-n < 0 )
            return;
        item.push_back(n);
        dfs(nums, target-n, idx, item);
        item.pop_back();
        dfs(nums, target, idx+1, item);
    }
    
};
```
      