[372.super-pow](https://leetcode.com/problems/super-pow/)  

Your task is to calculate _a__b_ mod 1337 where _a_ is a positive integer and _b_ is an extremely large positive integer given in the form of an array.

**Example 1:**

  
**Input:** a = 2, b = \[3\]
  
**Output:** 8
  

**Example 2:**

  
**Input:** a = 2, b = \[1,0\]
  
**Output:** 1024  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> m;
    int superPow(int a, vector<int>& b) {
        int p = 1;
        a %= 1337;
        for(int i = 0; i <= 9; ++i) {
            m.push_back(p);
            p *= a;
            p %= 1337;
        }
        long long res = 1;
        for(int i = 0; i < b.size(); ++i) {
            long long p = 1;
            for(int i = 0; i <10; ++i) {
                p *= res;
                p %= 1337;
            }
            res =(p * m[b[i]]) % 1337;
        }
        return res;
    }
};
```
      