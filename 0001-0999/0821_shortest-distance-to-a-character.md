[821.shortest-distance-to-a-character](https://leetcode.com/problems/shortest-distance-to-a-character/)  

Given a string `S` and a character `C`, return an array of integers representing the shortest distance from the character `C` in the string.

**Example 1:**

  
**Input:** S = "loveleetcode", C = 'e'
  
**Output:** \[3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0\]
  

**Note:**

1.  `S` string length is in `[1, 10000].`
2.  `C` is a single character, and guaranteed to be in string `S`.
3.  All letters in `S` and `C` are lowercase.  



**Solution:**  

```python
class Solution(object):
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        C_list = []
        for idx, char_s in enumerate(S):
            if char_s == C:
                C_list.append(idx)
        ans = []
        for idx, char_s in enumerate(S):
            if char_s != C:
                min_dis = 1000000
                for c_idx in C_list:
                    dis = abs(c_idx - idx)
                    if dis < min_dis:
                        min_dis = dis
                ans.append(min_dis)
            else:
                ans.append(0)
        return ans
```
      