[788.rotated-digits](https://leetcode.com/problems/rotated-digits/)  

X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other (on this case they are rotated in a different direction, in other words 2 or 5 gets mirrored); 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number `N`, how many numbers X from `1` to `N` are good?

**Example:**
**Input:** 10
**Output:** 4
**Explanation:** 
There are four good numbers in the range \[1, 10\] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

**Note:**

*   N  will be in range `[1, 10000]`.  



**Solution:**  

```cpp
class Solution {
public:
    int rotatedDigits(int N) {
        int num[10] = {0,1,5,-1,-1,2,9,-1,8,6};
        int ans = 0;
        for( int i = 1; i<=N; i++){
            int n = i;
            int new_num = 0;
            int bit=1;
            
            while(n>0){
                int a=n%10;
                n/=10;
                if(num[a] <0 ){
                    new_num = i;
                    break;
                }
                new_num = new_num+num[a]*(bit);
                bit*=10;
            }
           // printf("%d %d\n", new_num, i);
            if( new_num != i )
                ans++;
        }
        return ans;
    }
};
```
      