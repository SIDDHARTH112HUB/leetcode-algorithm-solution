[415.add-strings](https://leetcode.com/problems/add-strings/)  

Given two non-negative integers `num1` and `num2` represented as string, return the sum of `num1` and `num2`.

**Note:**

1.  The length of both `num1` and `num2` is < 5100.
2.  Both `num1` and `num2` contains only digits `0-9`.
3.  Both `num1` and `num2` does not contain any leading zero.
4.  You **must not use any built-in BigInteger library** or **convert the inputs to integer** directly.  



**Solution:**  

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size()-1, j=num2.size()-1;
        int carry = 0;
        while( i >= 0 || j >= 0 || carry > 0){
            int a = 0, b= 0;
            if( i >= 0 )
                a = num1[i] - '0';
            if( j >= 0 )
                b = num2[j] - '0';
            ans += ((a+b+carry) % 10) +'0';
            carry = int( a+b+carry >= 10 );
            i--;j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```
      