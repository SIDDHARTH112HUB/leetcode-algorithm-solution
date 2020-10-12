[117.populating-next-right-pointers-in-each-node-ii](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)  

Given a binary tree

  
struct Node {
  
  int val;
  
  Node \*left;
  
  Node \*right;
  
  Node \*next;
  
}
  

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

**Follow up:**

*   You may only use constant extra space.
*   Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/02/15/117_sample.png)

  
**Input:** root = \[1,2,3,4,5,null,7\]  
**Output:** \[1,#,2,3,#,4,5,7,#\]  
**Explanation:** Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.  

**Constraints:**

*   The number of nodes in the given tree is less than `6000`.
*   `-100 <= node.val <= 100`  



**Solution:**  

```cpp
class Solution {
public:
    Node* connect(Node *root) {
        if (!root) return NULL;
        Node *p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p; 
        if (root->left) root->left->next = root->right ? root->right : p;
        connect(root->right);
        connect(root->left);
        return root;
    }
};
```
      