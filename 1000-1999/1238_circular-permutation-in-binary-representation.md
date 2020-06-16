[1238.circular-permutation-in-binary-representation](https://leetcode.com/problems/circular-permutation-in-binary-representation/)  

Given 2 integers `n` and `start`. Your task is return **any** permutation `p` of `(0,1,2.....,2^n -1)` such that :

*   `p[0] = start`
*   `p[i]` and `p[i+1]` differ by only one bit in their binary representation.
*   `p[0]` and `p[2^n -1]` must also differ by only one bit in their binary representation.

**Example 1:**

  
**Input:** n = 2, start = 3  
**Output:** \[3,2,0,1\]  
**Explanation:** The binary representation of the permutation is (11,10,00,01).   
All the adjacent element differ by one bit. Another valid permutation is \[3,1,0,2\]  

**Example 2:**

  
**Input:** n = 3, start = 2  
**Output:** \[2,6,7,5,4,0,1,3\]  
**Explanation:** The binary representation of the permutation is (010,110,111,101,100,000,001,011).  

**Constraints:**

*   `1 <= n <= 16`
*   `0 <= start < 2 ^ n`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(1);
        for(int i = 1; i <n; ++i) {
            int size = arr.size();
            int num = 1 << i;
            for(int j = size - 1; j>=0; --j) {
                arr.push_back(num + arr[j]);
            }
        }
        vector<int> ans;
        int idx = -1;
        for(int i = 0; i <arr.size(); ++i) {
            if(arr[i] == start) {
                if(idx == -1)
                    idx = i;
            }
            if(idx >= 0) {
                ans.push_back(arr[i]);
            }
        }
        
        for(int i = 0; i < idx; ++i)
            ans.push_back(arr[i]);
        return ans;
    }
};
```
      