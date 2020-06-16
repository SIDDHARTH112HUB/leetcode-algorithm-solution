[416.partition-equal-subset-sum](https://leetcode.com/problems/partition-equal-subset-sum/)  

Given a **non-empty** array containing **only positive integers**, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

**Note:**

1.  Each of the array element will not exceed 100.
2.  The array size will not exceed 200.

**Example 1:**

  
Input: \[1, 5, 11, 5\]
  

  
Output: true
  

  
Explanation: The array can be partitioned as \[1, 5, 5\] and \[11\].
  

**Example 2:**

  
Input: \[1, 2, 3, 5\]
  

  
Output: false
  

  
Explanation: The array cannot be partitioned into equal sum subsets.  



**Solution:**  

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if( sum % 2 ) return false;
        int target = sum / 2;
        sort(nums.begin(), nums.end());
        bool dp[target+1] = {0};
        dp[0] = true;
        for( int i =0; i< nums.size(); i++ ){
            int n = nums[i];
            for( int j = target; j>=n; j--){
                dp[j] = dp[j] || dp[j-n];
            }
        }
        return dp[target];
    }
    /*
    unordered_map<int, unordered_map<int, bool> > m;
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if( sum % 2 ) return false;
        sort(nums.begin(), nums.end());
        return solve(nums, 0, sum/2);
    }
    bool solve( vector<int> &nums, int idx, int sum ){
        if( idx >= nums.size() ) return sum == 0;
        if( sum < nums[idx]) return false;
        
        if( m[idx].count(sum) ) return m[idx][sum];
        bool res = false;
        int upper = upper_bound(nums.begin(), nums.end(), nums[idx]) - nums.begin();
        for( int i = idx; i<=upper; i++){
            res = solve(nums, upper, sum - (i-idx)*nums[idx] );
            if( res ){
                m[idx][sum] = true;
                return res;
            }
        }
        m[idx][sum] = false;
        //res = solve( nums, upper, sum);
        return false;
    }*/
};
```
      