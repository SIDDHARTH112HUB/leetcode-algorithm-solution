[410.split-array-largest-sum](https://leetcode.com/problems/split-array-largest-sum/)  

Given an array which consists of non-negative integers and an integer _m_, you can split the array into _m_ non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these _m_ subarrays.

**Note:**  
If _n_ is the length of array, assume the following constraints are satisfied:

*   1 ≤ _n_ ≤ 1000
*   1 ≤ _m_ ≤ min(50, _n_)

**Examples:**

Input:
**nums** = \[7,2,5,10,8\]
**m** = 2

Output:
18

Explanation:
There are four ways to split **nums** into two subarrays.
The best way is to split it into **\[7,2,5\]** and **\[10,8\]**,
where the largest sum among the two subarrays is only 18.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, unordered_map<int, int> > M;
    int splitArray(vector<int>& nums, int m) {
        return solve(nums, 0, m);
    }
    
    int solve(vector<int>& nums, int start, int m) {
        int sum = 0;
        if(m == 1){
            for(int i =  start; i < nums.size(); ++i)
                sum += nums[i];
            return sum;
        }
        if(M[start].count(m)) return M[start][m];
        int ans = INT_MAX;
        for(int i = start; i <= nums.size() - m; ++i) {
            sum += nums[i];
            if(sum > ans)
                break;
            int res = max(sum, solve(nums, i + 1, m - 1));
            ans = min(res, ans);
        }
        M[start][m] = ans;
        return ans;
    }
};
```
      