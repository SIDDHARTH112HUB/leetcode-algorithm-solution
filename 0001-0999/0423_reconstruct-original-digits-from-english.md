[423.reconstruct-original-digits-from-english](https://leetcode.com/problems/reconstruct-original-digits-from-english/)  

Given a **non-empty** string containing an out-of-order English representation of digits `0-9`, output the digits in ascending order.

**Note:**  

1.  Input contains only lowercase English letters.
2.  Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
3.  Input length is less than 50,000.

**Example 1:**  

  
Input: "owoztneoer"
  

  
Output: "012"
  

**Example 2:**  

  
Input: "fviefuro"
  

  
Output: "45"  



**Solution:**  

```cpp
class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(128), nums(10);
        for( char c : s) ++count[c];
        nums[0] = count['z'];
        nums[2] = count['w'];
        nums[4] = count['u'];
        nums[6] = count['x'];
        nums[8] = count['g'];
        nums[1] = count['o'] - nums[0]- nums[2]-nums[4];
        nums[3] = count['h'] - nums[8];
        nums[5] = count['f'] - nums[4];
        nums[7] = count['s'] - nums[6];
        nums[9] = count['i'] - nums[5] - nums[8]-nums[6];
        string ans="";
        for( int i = 0; i<nums.size(); i++){
            for( int j = 0; j<nums[i]; j++){
                ans += (i+'0');
            }
        }
        return ans;
    }
};
```
      