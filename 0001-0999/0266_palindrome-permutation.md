[266.palindrome-permutation](https://leetcode.com/problems/palindrome-permutation/)  

Given a string, determine if a permutation of the string could form a palindrome.

**Example 1:**

  
**Input:** `"code"`
  
**Output:** false

**Example 2:**

  
**Input:** `"aab"`
  
**Output:** true

**Example 3:**

  
**Input:** `"carerac"`
  
**Output:** true  



**Solution:**  

```cpp
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<int,int> m;
        for(auto c : s) ++m[c];
        int odd = 0;
        for(auto it : m)
            odd += it.second % 2;
        return odd <= 1;
    }
};
```
      