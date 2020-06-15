[523.continuous-subarray-sum](https://leetcode.com/problems/continuous-subarray-sum/)  

Given a list of **non-negative** numbers and a target **integer** k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of **k**, that is, sums up to n\*k where n is also an **integer**.

**Example 1:**

**Input:** \[23, 2, 4, 6, 7\],  k=6
**Output:** True
**Explanation:** Because \[2, 4\] is a continuous subarray of size 2 and sums up to 6.

**Example 2:**

**Input:** \[23, 2, 6, 4, 7\],  k=6
**Output:** True
**Explanation:** Because \[23, 2, 6, 4, 7\] is an continuous subarray of size 5 and sums up to 42.

**Constraints:**

*   The length of the array won't exceed 10,000.
*   You may assume the sum of all the numbers is in the range of a signed 32-bit integer.  



**Solution:**  

```cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        int size = nums.size();
        if( size <= 1 ) return false;
        
            for( int i = 1; i<nums.size(); i++){
                if( nums[i-1] == 0 && nums[i] == 0)
                    return true;
                
            }
        if( k == 0 ){
            return false;
        }
        int sum = 0;
        if( k < 0 ) k *= -1;
        //cout<<k<<endl;
        m[0] = 1;
        for( int i = 0; i<nums.size(); i++){
            sum += nums[i];
            //if( nums[i] % k == 0 )continue;
            //if( sum % k == 0 && i > 0 ) return true;
            if( m[sum % k] > 0 && m[sum%k] -2 <= i-2){
                //if( i - m[sum % k]+1 >= 2 )
                //    return true;
                //else
                //    m[sum%k] = i+1;
                return true;
            }
            if( m[sum%k] == 0 ){
                m[sum%k] = i+2;
            }
        }
        cout<<sum<<endl;
        return false;
    }
};
```
      