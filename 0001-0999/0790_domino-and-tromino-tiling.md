[790.domino-and-tromino-tiling](https://leetcode.com/problems/domino-and-tromino-tiling/)  

We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape. These shapes may be rotated.

  
XX  <- domino
  

  
XX  <- "L" tromino
  
X
  

Given N, how many ways are there to tile a 2 x N board? **Return your answer modulo 10^9 + 7**.

(In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.)

  
**Example:**
  
**Input:** 3
  
**Output:** 5
  
**Explanation:** 
  
The five different ways are listed below, different letters indicates different tiles:
  
XYZ XXZ XYY XXY XYY
  
XYZ YYZ XZZ XYY XXY

**Note:**

*   N  will be in range `[1, 1000]`.  



**Solution:**  

```cpp
class Solution {
public:
    int numTilings(int N) {
        if( N ==1 ) return 1;
        if( N ==2 ) return 2;
        if( N== 3 ) return 5;
        if( N == 4 ) return 11;
        //if(N ==5 ) return 24;
        //if( N ==6 ) return 53;
        //if( N == 7 ) return 117;
        //if(N == 8 ) return 258;
        int prev=3;
        int cur = 5;
        int ans = 5;
        long long NN[1010];
        NN[1] = 1;
        NN[2] = 2;
        NN[3] = 5;
        NN[4] = 11;
        for( int i = 5; i<=N; i++){
            NN[i] = (NN[i-1]*2 + NN[i-3])%1000000007;
        }
        return NN[N];
    }
};
```
      