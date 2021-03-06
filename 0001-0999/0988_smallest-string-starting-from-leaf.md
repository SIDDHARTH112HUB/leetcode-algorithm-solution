[988.smallest-string-starting-from-leaf](https://leetcode.com/problems/smallest-string-starting-from-leaf/)  

Given the `root` of a binary tree, each node has a value from `0` to `25` representing the letters `'a'` to `'z'`: a value of `0` represents `'a'`, a value of `1` represents `'b'`, and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

_(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, `"ab"` is lexicographically smaller than `"aba"`.  A leaf of a node is a node that has no children.)_

**Example 1:**

**![](https://assets.leetcode.com/uploads/2019/01/30/tree1.png)**

  
**Input:** \[0,1,2,3,4,3,4\]
  
**Output:** "dba"
  

**Example 2:**

**![](https://assets.leetcode.com/uploads/2019/01/30/tree2.png)**

  
**Input:** \[25,1,3,1,3,0,2\]
  
**Output:** "adz"
  

**Example 3:**

**![](https://assets.leetcode.com/uploads/2019/02/01/tree3.png)**

  
**Input:** \[2,2,1,null,1,0,null,0\]
  
**Output:** "abc"
  

**Note:**

1.  The number of nodes in the given tree will be between `1` and `8500`.
2.  Each node in the tree will have a value between `0` and `25`.  



**Solution:**  

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {string}
 */
var c = "abcdefghijklmnopqrstuvwxyz";
var ans = ""
var smallestFromLeaf = function(root) {
    if( !root ) return "";
    ans = "";
    solve(root, "");
    return ans;
};

var solve = function(node, str){
    if( !node ) return;
    str += c[node.val];
    if( !node.left && !node.right ){
        var ns = str.split("").reverse().join("");
        if( ans == "" || ans > ns )
            ans = ns;
        return;
    }
    solve(node.left, str);
    solve(node.right, str);
}
```
      