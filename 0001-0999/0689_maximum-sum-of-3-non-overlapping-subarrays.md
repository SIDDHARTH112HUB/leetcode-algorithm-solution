[689.maximum-sum-of-3-non-overlapping-subarrays](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)  

In a given array `nums` of positive integers, find three non-overlapping subarrays with maximum sum.

Each subarray will be of size `k`, and we want to maximize the sum of all `3*k` entries.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

**Example:**

  
**Input:** \[1,2,1,2,6,7,5,1\], 2
  
**Output:** \[0, 3, 5\]
  
**Explanation:** Subarrays \[1, 2\], \[2, 6\], \[7, 5\] correspond to the starting indices \[0, 3, 5\].
  
We could have also taken \[2, 1\], but an answer of \[1, 3, 5\] would be lexicographically larger.
  

**Note:**

*   `nums.length` will be between 1 and 20000.
*   `nums[i]` will be between 1 and 65535.
*   `k` will be between 1 and floor(nums.length / 3).  



**Solution:**  

```cpp
class Solution {
public:
    map<int, vector<int> > m;
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sums;
        int len = nums.size() - k + 1;
        int sum = 0;
        for( int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if( i >= k - 1){
                sum -= i<k?0:nums[i-k];
                sums.push_back(sum);
                //cout<<sum<<" ";
            }
        }
        //cout<<endl;
        int left[len] = {0};
        int best = 0;
        for( int i = 0; i< len ; i++){
            if( sums[i] > sums[best] ){
                best = i;
            }
            left[i] = best;
        }
        int right[len]= {0};
        best = len-1;
        for( int i = len-1; i>=0; i--){
            if( sums[i] > sums[best])
                best = i;
            right[i] = best;
        }
        vector<int> res = {0, k, 2*k};
        for( int i = k; i< len-k; i++){
            if( sums[left[i-k]] + sums[i]+sums[right[i+k]] >  sums[res[0]] + sums[res[1]]+sums[res[2]] ){
                res[0] = left[i-k];
                res[1] = i;
                res[2] = right[i+k];
            }
        }
        return res;
    }
};
```
      