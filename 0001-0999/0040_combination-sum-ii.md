[40.combination-sum-ii](https://leetcode.com/problems/combination-sum-ii/)  

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:**

*   All numbers (including `target`) will be positive integers.
*   The solution set must not contain duplicate combinations.

**Example 1:**

  
**Input:** candidates = `[10,1,2,7,6,1,5]`, target = `8`,
  
**A solution set is:**
  
\[
  
  \[1, 7\],
  
  \[1, 2, 5\],
  
  \[2, 6\],
  
  \[1, 1, 6\]
  
\]
  

**Example 2:**

  
**Input:** candidates = \[2,5,2,1,2\], target = 5,
  
**A solution set is:**
  
\[
  
  \[1,2,2\],
  
  \[5\]
  
\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& num, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(num.begin(), num.end());
        helper(num, target, 0, out, res);
        return res;
    }
    void helper(vector<int>& num, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) { res.push_back(out); return; }
        for (int i = start; i < num.size(); ++i) {
            if (i > start && num[i] == num[i - 1]) continue;
            out.push_back(num[i]);
            helper(num, target - num[i], i + 1, out, res);
            out.pop_back();
        }
    }
};
```
      