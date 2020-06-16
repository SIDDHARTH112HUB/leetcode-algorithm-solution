[779.k-th-symbol-in-grammar](https://leetcode.com/problems/k-th-symbol-in-grammar/)  

On the first row, we write a `0`. Now in every subsequent row, we look at the previous row and replace each occurrence of `0` with `01`, and each occurrence of `1` with `10`.

Given row `N` and index `K`, return the `K`\-th indexed symbol in row `N`. (The values of `K` are 1-indexed.) (1 indexed).

  
**Examples:**
  
**Input:** N = 1, K = 1
  
**Output:** 0
  

  
**Input:** N = 2, K = 1
  
**Output:** 0
  

  
**Input:** N = 2, K = 2
  
**Output:** 1
  

  
**Input:** N = 4, K = 5
  
**Output:** 1
  

  
**Explanation:**
  
row 1: 0
  
row 2: 01
  
row 3: 0110
  
row 4: 01101001
  

**Note:**

1.  `N` will be an integer in the range `[1, 30]`.
2.  `K` will be an integer in the range `[1, 2^(N-1)]`.  



**Solution:**  

```cpp
class Solution {
public:
    int kthGrammar(int N, int K) {
        int ans[4] = {0,1,1,0};
        int ans_ver[4]=  {1,0,0,1};
        
        int count = 0 ;
        while( K > 4 ){
            int n = 1;
            while( n * 2 < K ){
            n *= 2;
            }
            K -= n;
            count++;
            n /= 2;
        }
        if( count % 2 == 0 )
            return ans[K-1];
        else
            return ans_ver[K-1];
    }
};
```
      