[869.reordered-power-of-2](https://leetcode.com/problems/reordered-power-of-2/)  

Starting with a positive integer `N`, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return `true` if and only if we can do this in a way such that the resulting number is a power of 2.

**Example 1:**

  
**Input:** 1
  
**Output:** true
  

**Example 2:**

  
**Input:** 10
  
**Output:** false
  

**Example 3:**

  
**Input:** 16
  
**Output:** true
  

**Example 4:**

  
**Input:** 24
  
**Output:** false
  

**Example 5:**

  
**Input:** 46
  
**Output:** true
  

**Note:**

1.  `1 <= N <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> num;
    bool reorderedPowerOf2(int N) {
        if( N == 0 ) return false;
        
        while( N > 0 ){
            num.push_back( N%10);
            N /= 10;
        }
        
        return dfs(0, 0, 0);
    }
    bool dfs( int idx, int res, bool zero ){
        
        if( idx >= num.size() ){
            if( zero )
                return false;
            return !(res & (res-1));
        }
        for( int i = 0; i<num.size(); i++ ){
            if( num[i] != -1 ){
                int src = num[i];
                num[i] = -1;
                
                bool b = dfs(idx+1, res + pow(10, idx) * src, src == 0);
                if( b == true )
                    return true;
                num[i] = src;
            }
        }
        return false;
    }
};
```
      