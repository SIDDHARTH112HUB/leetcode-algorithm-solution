[728.self-dividing-numbers](https://leetcode.com/problems/self-dividing-numbers/)  

A _self-dividing number_ is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

**Example 1:**  

  
**Input:** 
  
left = 1, right = 22
  
**Output:** \[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22\]
  

**Note:**

*   The boundaries of each input argument are `1 <= left <= right <= 10000`.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int num = left; num<=right; num++){
            if( num <= 0 )
                continue;
            int n = num;
            while(n>0){
                if( n % 10 == 0 )
                    break;
                int m = n % 10;
                if( num % m == 0 )
                    n = n / 10;
                else
                    break;
            }
            if( n == 0 )
                ans.push_back(num);
        }
        return ans;
    }
};
```
      