[927.three-equal-parts](https://leetcode.com/problems/three-equal-parts/)  

Given an array `A` of `0`s and `1`s, divide the array into 3 non-empty parts such that all of these parts represent the same binary value.

If it is possible, return **any** `[i, j]` with `i+1 < j`, such that:

*   `A[0], A[1], ..., A[i]` is the first part;
*   `A[i+1], A[i+2], ..., A[j-1]` is the second part, and
*   `A[j], A[j+1], ..., A[A.length - 1]` is the third part.
*   All three parts have equal binary value.

If it is not possible, return `[-1, -1]`.

Note that the entire part is used when considering what binary value it represents.  For example, `[1,1,0]` represents `6` in decimal, not `3`.  Also, leading zeros are allowed, so `[0,1,1]` and `[1,1]` represent the same value.

**Example 1:**

**Input:** \[1,0,1,0,1\]
**Output:** \[0,3\]

**Example 2:**

**Input:** \[1,1,0,1,1\]
**Output:** \[-1,-1\]

**Note:**

1.  `3 <= A.length <= 30000`
2.  `A[i] == 0` or `A[i] == 1`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int lastzeros = 0, ones = 0;
        for( int i = A.size()-1; i >= 0; i--){
            int n = A[i];
            if( n == 0 && ones == 0 )
                lastzeros++;
            if( n == 1 )
                ones++;
        }
        if( ones == 0 )
            return {0,A.size()-1};
        if( ones % 3 ) return {-1,-1};
        int first = 0, second = 0;
        int fone  = ones/3;
        for( int i = 0; i< A.size(); i++ ){
            if( fone > 0 && A[i] == 1){
                fone--;
                if( fone == 0 ){
                    first = i+lastzeros;
                    break;
                }
                continue;
            }
        }
        fone = ones/3;
        for( int i = first+1; i< A.size(); i++ ){
            if( fone > 0 && A[i] == 1){
                fone--;
                if( fone == 0 ){
                    second = i+lastzeros;
                    break;
                }
                continue;
            }
        }
        int f = 0, s = first+1, t = second + 1;
        while( A[f] == 0 )f++;
        while( A[s] == 0 )s++;
        while( A[t] == 0 )t++;
        string fs, ss, ts;
        while( f<=first)
            fs+= A[f++]+'0';
        while( s <= second)
            ss+= A[s++]+'0';
        while( t < A.size() )
            ts+= A[t++]+'0';
        if( fs == ss && ss == ts )
            return {first, second+1};
        else
            return {-1,-1};
    }
};
```
      