[90.subsets-ii](https://leetcode.com/problems/subsets-ii/)  

Given a collection of integers that might contain duplicates, **_nums_**, return all possible subsets (the power set).

**Note:** The solution set must not contain duplicate subsets.

**Example:**

**Input:** \[1,2,2\]
**Output:**
\[
  \[2\],
  \[1\],
  \[1,2,2\],
  \[2,2\],
  \[1,2\],
  \[\]
\]  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> item;
        dfs(nums, 0, item);
        return ans;
    }
    void dfs(vector<int> &nums, int idx, vector<int> &item){
        int size = nums.size();
        if( idx >= size ){
            ans.push_back(item);
            return;
        }
        int n = nums[idx];
        int upper = upper_bound(nums.begin(), nums.end(), n)-nums.begin();
        for( int i = idx; i<=upper; i++){
            int cnt = i-idx;
            while(cnt-->0)
                item.push_back(n);
            dfs(nums, upper, item);
            cnt = i-idx;
            while( cnt-->0)
                item.pop_back();
        }
    }
};
```
      