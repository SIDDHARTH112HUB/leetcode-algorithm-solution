[906.super-palindromes](https://leetcode.com/problems/super-palindromes/)  

Let's say a positive integer is a _superpalindrome_ if it is a palindrome, and it is also the square of a palindrome.

Now, given two positive integers `L` and `R` (represented as strings), return the number of superpalindromes in the inclusive range `[L, R]`.

**Example 1:**

**Input:** L = "4", R = "1000"
**Output:** 4
**Explanation**: 4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 \* 26 = 676, but 26 is not a palindrome.

**Note:**

1.  `1 <= len(L) <= 18`
2.  `1 <= len(R) <= 18`
3.  `L` and `R` are strings representing integers in the range `[1, 10^18)`.
4.  `int(L) <= int(R)`  



**Solution:**  

```cpp
class Solution {
public:
    
    int superpalindromesInRange(string L, string R) {
        long long l = stoll(L), r = stoll(R);
        int ans = 0;
        for( int i = 0; i<=100000; i++){
            for( int p = 0; p < 2; p++){
                if( i >= 10000 && p == 0 ) continue;
                long long n = i, t = i;
                if( p == 1) t/=10;
                while(t>0){
                    n =  n* 10 + t%10;
                    t /= 10;
                }
                n = n * n;
                if( n < l || n > r) continue;
                string s = to_string(n);
                bool ok = true;
                for( int j = 0; j < s.size()/2; j++){
                    if( s[j] != s[s.size()-j-1]){
                        ok = false;
                        break;
                    }
                        
                }
                if( ok )
                    ans++;
            }
        }
        return ans;
    }
};
```
      