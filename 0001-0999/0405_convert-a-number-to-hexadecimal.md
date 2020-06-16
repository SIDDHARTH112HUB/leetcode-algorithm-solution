[405.convert-a-number-to-hexadecimal](https://leetcode.com/problems/convert-a-number-to-hexadecimal/)  

Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, [two’s complement](https://en.wikipedia.org/wiki/Two%27s_complement) method is used.

**Note:**

1.  All letters in hexadecimal (`a-f`) must be in lowercase.
2.  The hexadecimal string must not contain extra leading `0`s. If the number is zero, it is represented by a single zero character `'0'`; otherwise, the first character in the hexadecimal string will not be the zero character.
3.  The given number is guaranteed to fit within the range of a 32-bit signed integer.
4.  You **must not use _any_ method provided by the library** which converts/formats the number to hex directly.

**Example 1:**

  
Input:
  
26
  

  
Output:
  
"1a"
  

**Example 2:**

  
Input:
  
-1
  

  
Output:
  
"ffffffff"  



**Solution:**  

```cpp
class Solution {
public:
    string toHex(int num) {
        if( num == 0 ) return "0";
        unsigned int n = (unsigned int)num;
        string ans;
        char c[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        int idx = 0;
        while(n !=0 ){
            ans += c[n%16];
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      