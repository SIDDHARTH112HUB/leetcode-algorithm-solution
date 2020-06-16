[9.palindrome-number](https://leetcode.com/problems/palindrome-number/)  

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

**Example 1:**

  
**Input:** 121
  
**Output:** true
  

**Example 2:**

  
**Input:** -121
  
**Output:** false
  
**Explanation:** From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
  

**Example 3:**

  
**Input:** 10
  
**Output:** false
  
**Explanation:** Reads 01 from right to left. Therefore it is not a palindrome.
  

**Follow up:**

Coud you solve it without converting the integer to a string?  



**Solution:**  

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0)  return false;
        if( x < 10 ) return true;
        int check = 1000000000;
        while( x/check == 0)
        {
            check/=10;
        }
        while( x/check == x%10 )
        {
            
            x = x%check;
            x/=10;
            check/=100;
            if( x < 10 && check<=10 )
                return true;
        }
        return false;
    }
};
```
      