[796.rotate-string](https://leetcode.com/problems/rotate-string/)  

We are given two strings, `A` and `B`.

A _shift on `A`_ consists of taking string `A` and moving the leftmost character to the rightmost position. For example, if `A = 'abcde'`, then it will be `'bcdea'` after one shift on `A`. Return `True` if and only if `A` can become `B` after some number of shifts on `A`.

**Example 1:**
**Input:** A = 'abcde', B = 'cdeab'
**Output:** true

**Example 2:**
**Input:** A = 'abcde', B = 'abced'
**Output:** false

**Note:**

*   `A` and `B` will have length at most `100`.  



**Solution:**  

```cpp
class Solution {
public:
    bool rotateString(string A, string B) {
        if( A.length()== 0 ) return true;
        if( A.length() == 1 && A[0] == B[0] ) return true;
        for( int i = 0; i<A.length(); i++){
            if( B[0] == A[i] ){
                int right = i;
                int b_left = 0;
                while(right<A.size() && A[right] == B[b_left]){
                    right++;
                    b_left++;
                }
                if(b_left == A.length())
                    return true;
                if( right == A.length()){
                    int a_left = 0;
                    while(b_left<B.length() && B[b_left] == A[a_left]){
                        a_left++;
                        b_left++;
                    }
                    if( b_left == B.length())
                        return true;
                }
            }
        }
        return false;
    }
};
```
      