[1191.k-concatenation-maximum-sum](https://leetcode.com/problems/k-concatenation-maximum-sum/)  

Given an integer array `arr` and an integer `k`, modify the array by repeating it `k` times.

For example, if `arr = [1, 2]` and `k = 3` then the modified array will be `[1, 2, 1, 2, 1, 2]`.

Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be `0` and its sum in that case is `0`.

As the answer can be very large, return the answer **modulo** `10^9 + 7`.

**Example 1:**

  
**Input:** arr = \[1,2\], k = 3  
**Output:** 9  

**Example 2:**

  
**Input:** arr = \[1,-2,1\], k = 5  
**Output:** 2  

**Example 3:**

  
**Input:** arr = \[-1,-2\], k = 7  
**Output:** 0  

**Constraints:**

*   `1 <= arr.length <= 10^5`
*   `1 <= k <= 10^5`
*   `-10^4 <= arr[i] <= 10^4`  



**Solution:**  

```cpp
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long mx = *max_element(arr.begin(), arr.end());
        if(mx <= 0) return 0;
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        long long ans = sum;
        int size = arr.size();
        for(int i = 0; i < size*2; ++i) {
            arr.push_back(arr[i%size]);
        }
        if(k > 1) size *= 2;
        long long res = 0;
        sum = 0;
        mx = 0;
        for(int i = 0; i < arr.size(); ++i) {
            sum = max((long long)arr[i] + sum, (long long)arr[i]);
            res = max(res, sum);
        }
        long long mn1 = 0, mn2 = 0;
        sum = 0;
        long long sum2 = 0;
        int l = 0;
        for(int i = 0; i < size; ++i) {
            sum += arr[i];
            if(sum < mn1){
                mn1 = sum;
                l = i + 1;
            }
        }
        for(int i = size - 1; i > l; --i) {
            sum2 += arr[i];
            if(sum2 < mn2){
                mn2 = sum2;
            }
        }
        return max(max(ans, res),  ans * k - (mn1 < 0 ? mn1 : 0) - (mn2 < 0 ?mn2 :0)) % 1000000007;
    }
};
```
      