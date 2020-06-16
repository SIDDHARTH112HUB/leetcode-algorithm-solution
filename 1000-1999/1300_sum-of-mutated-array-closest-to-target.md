[1300.sum-of-mutated-array-closest-to-target](https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/)  

Given an integer array `arr` and a target value `target`, return the integer `value` such that when we change all the integers larger than `value` in the given array to be equal to `value`, the sum of the array gets as close as possible (in absolute difference) to `target`.

In case of a tie, return the minimum such integer.

Notice that the answer is not neccesarilly a number from `arr`.

**Example 1:**

  
**Input:** arr = \[4,9,3\], target = 10  
**Output:** 3  
**Explanation:** When using 3 arr converts to \[3, 3, 3\] which sums 9 and that's the optimal answer.  

**Example 2:**

  
**Input:** arr = \[2,3,5\], target = 10  
**Output:** 5  

**Example 3:**

  
**Input:** arr = \[60864,25176,27249,21296,20204\], target = 56803  
**Output:** 11361  

**Constraints:**

*   `1 <= arr.length <= 10^4`
*   `1 <= arr[i], target <= 10^5`  



**Solution:**  

```cpp
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> prefix = arr;
        for(int i = 1; i < arr.size(); ++i) {
            prefix[i] += prefix[i-1];
        }
        int mx = INT_MAX;
        int ans;
        int cur;
        int l = 0, r = arr.back();
        int mid;
        while(l <= r) {
            mid = (l +r) /2;
            int idx = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int sum = mid * (prefix.size() - idx) + (idx > 0 ? prefix[idx - 1] : 0);
            //cout<<arr[idx]<<" sum:"<<sum<<" abs:"<<abs(sum - target)<<endl;
            int aa = abs(sum - target);
            if(aa <= mx) {
                if(aa == mx) {
                    if(sum < target){
                        cur = mid;
                    }
                }else {
                    mx = aa;
                    cur = mid;
                }
            }
            if(sum >= target) {
                r = mid - 1;
            }else
                l = mid + 1;
                
        }
        //cout<<mid<<" "<<cur<<endl;
        return cur;
    }
};
```
      