[462.minimum-moves-to-equal-array-elements-ii](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)  

Given a **non-empty** integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

**Example:**

**Input:**
\[1,2,3\]

**Output:**
2

**Explanation:**
Only two moves are needed (remember each move increments or decrements one element):

\[1,2,3\]  =>  \[2,2,3\]  =>  \[2,2,2\]  



**Solution:**  

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(auto n : nums) {
            ans += abs(n - nums[nums.size()/2]);
        }
        return ans;
        /*
        vector<long long> pre(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            pre[i] = (i > 0 ? pre[i - 1] : 0) + nums[i];
        }
        long long ans = INT_MAX;
        long long size = nums.size();
        for(long long i = 0; i < nums.size(); ++i) {
            long long n = nums[i];
            long long sum = n * i - (i > 0 ? pre[i-1]: 0 * i) + (pre[size - 1] - pre[i]) - n * (size - i - 1);
            ans = min(ans, sum);
        }
        return ans;*/
    }
};
```
      