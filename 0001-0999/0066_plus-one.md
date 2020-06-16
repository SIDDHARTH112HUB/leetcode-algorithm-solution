[66.plus-one](https://leetcode.com/problems/plus-one/)  

Given a **non-empty** array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

**Example 1:**

  
**Input:** \[1,2,3\]
  
**Output:** \[1,2,4\]
  
**Explanation:** The array represents the integer 123.
  

**Example 2:**

  
**Input:** \[4,3,2,1\]
  
**Output:** \[4,3,2,2\]
  
**Explanation:** The array represents the integer 4321.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for( int i = digits.size()-1; i>=0; i--){
            int &n = digits[i];
            n+=carry;
            carry = n/10;
            n = n%10;
            if( !carry )
                return digits;
        }
        if( carry ){
            vector<int> ans(digits.size()+1, 0);
            ans[0] = 1;
            return ans;
        }else{
            return digits;
        }
        
    }
};
```
      