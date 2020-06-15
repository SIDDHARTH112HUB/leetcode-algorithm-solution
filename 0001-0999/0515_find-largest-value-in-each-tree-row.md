[515.find-largest-value-in-each-tree-row](https://leetcode.com/problems/find-largest-value-in-each-tree-row/)  

You need to find the largest value in each row of a binary tree.

**Example:**  

**Input:** 

          1
         / \\
        3   2
       / \\   \\  
      5   3   9 

**Output:** \[1, 3, 9\]  



**Solution:**  

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return [];
        res = []
        self.find(root, 0, res)
        return res;
    def find(self, node, depth, res):
        l = len(res)
        if l-1<depth:
            res.append(node.val)
        elif res[depth] < node.val:
            res[depth] = node.val
        if node.left:
            self.find(node.left, depth+1, res)
        if node.right:
            self.find( node.right, depth+1, res)
        return res
```
      