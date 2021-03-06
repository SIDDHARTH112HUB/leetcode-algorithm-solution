[1017.convert-to-base-2](https://leetcode.com/problems/convert-to-base-2/)  

Given a number `N`, return a string consisting of `"0"`s and `"1"`s that represents its value in base `**-2**` (negative two).

The returned string must have no leading zeroes, unless the string is `"0"`.

**Example 1:**

  
**Input:** 2
  
**Output:** "110"
  
**Explantion:** (-2) ^ 2 + (-2) ^ 1 = 2
  

**Example 2:**

  
**Input:** 3
  
**Output:** "111" **Explantion:** (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3
  

**Example 3:**

  
**Input:** 4
  
**Output:** "100" **Explantion:** (-2) ^ 2 = 4
  

**Note:**

1.  `0 <= N <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    string baseNeg2(int N) {
        if(N==0) return "0";
        string ans;
        long long n = 1;
        int sign = 1;
        while(N>0){
            if(N & n){
                N -= sign*n;
                ans+="1";
            }else
                ans+="0";
            sign *= -1;
            n = n << 1;       
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      