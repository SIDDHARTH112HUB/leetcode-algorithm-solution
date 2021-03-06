[331.verify-preorder-serialization-of-a-binary-tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)  

One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as `#`.

  
     \_9\_
  
    /   \\
  
   3     2
  
  / \\   / \\
  
 4   1  #  6
  
/ \\ / \\   / \\
  
# # # #   # #
  

For example, the above binary tree can be serialized to the string `"9,3,4,#,#,1,#,#,2,#,6,#,#"`, where `#` represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character `'#'` representing `null` pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as `"1,,3"`.

**Example 1:**

  
**Input:** `"9,3,4,#,#,1,#,#,2,#,6,#,#"`
  
**Output:** `true`

**Example 2:**

  
**Input:** `"1,#"`
  
**Output:** `false`
  

**Example 3:**

  
**Input:** `"9,#,#,1"`
  
**Output:** `false`  



**Solution:**  

```cpp
class Solution {
public:
    bool isValidSerialization(string s) {
        int idx = 0;
        return f(s, idx) && idx == s.size();
    }
    
    bool f(string &s, int &idx) {
        if(idx >= s.size()) return false;
        if(s[idx] == '#') {
            idx = min(idx+2, (int)s.size());
            return true;
        }
        while(idx < s.size() && s[idx++] != ',');
        return f(s, idx) && f(s, idx);
    }
};
```
      