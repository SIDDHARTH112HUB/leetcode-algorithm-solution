[984.string-without-aaa-or-bbb](https://leetcode.com/problems/string-without-aaa-or-bbb/)  

Given two integers `A` and `B`, return **any** string `S` such that:

*   `S` has length `A + B` and contains exactly `A` `'a'` letters, and exactly `B` `'b'` letters;
*   The substring `'aaa'` does not occur in `S`;
*   The substring `'bbb'` does not occur in `S`.

**Example 1:**

  
**Input:** A = 1, B = 2
  
**Output:** "abb" **Explanation:** "abb", "bab" and "bba" are all correct answers.
  

**Example 2:**

  
**Input:** A = 4, B = 1
  
**Output:** "aabaa"

**Note:**

1.  `0 <= A <= 100`
2.  `0 <= B <= 100`
3.  It is guaranteed such an `S` exists for the given `A` and `B`.  



**Solution:**  

```cpp
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        if( A >= B )
            return helper(A, B, 'a', 'b');
        return helper(B, A, 'b', 'a');
    }
    
    string helper(int n1, int n2, char a, char b){
        string ans;
        while( n1 > n2 && n1 >= 2 && n2 > 0 ){
            ans += a;
            ans += a;
            n1 -= 2;
            ans += b;
            n2 -= 1;
        }
        while( n1 > 0 || n2 > 0 ){
            if( n1-- > 0 )
                ans += a;
            if( n2-- > 0)
                ans+=b;
        }
        return ans;
    }
};
```
      