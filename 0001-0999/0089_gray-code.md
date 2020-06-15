[89.gray-code](https://leetcode.com/problems/gray-code/)  

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer _n_ representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

**Example 1:**

**Input:** 2
**Output:** `[0,1,3,2]`
**Explanation:**
00 - 0
01 - 1
11 - 3
10 - 2

For a given _n_, a gray code sequence may not be uniquely defined.
For example, \[0,2,3,1\] is also a valid gray code sequence.

00 - 0
10 - 2
11 - 3
01 - 1

**Example 2:**

**Input:** 0
**Output:** `[0]
**Explanation:** We define the gray code sequence to begin with 0.
             A gray code sequence of _n_ has size = 2n, which for _n_ = 0 the size is 20 = 1.
             Therefore, for _n_ = 0 the gray code sequence is [0].`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int pow = 1;
        for( int i = 1; i<=n; i++ ){
            int N = ans.size();
            if( i > 1 )pow*=2;
            for( int j = N-1; j>=0; j-- ){
                ans.push_back(ans[j] + pow);
            }
        }
        return ans;
    }
};
```
      