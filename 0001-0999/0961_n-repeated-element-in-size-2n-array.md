[961.n-repeated-element-in-size-2n-array](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/)  

In a array `A` of size `2N`, there are `N+1` unique elements, and exactly one of these elements is repeated N times.

Return the element repeated `N` times.

**Example 1:**

  
**Input:** \[1,2,3,3\]
  
**Output:** 3
  

**Example 2:**

  
**Input:** \[2,1,2,5,3,2\]
  
**Output:** 2
  

**Example 3:**

  
**Input:** \[5,1,5,2,5,3,5,4\]
  
**Output:** 5
  

**Note:**

1.  `4 <= A.length <= 10000`
2.  `0 <= A[i] < 10000`
3.  `A.length` is even  



**Solution:**  

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int n = A.size() /2;
        unordered_map<int, int> m;
        for( auto num: A ){
            ++m[num];
            if( m[num] == n )
                return num;
        }
        return -1;
    }
};
```
      