[431.encode-n-ary-tree-to-binary-tree](https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/)  

Design an algorithm to encode an N-ary tree into a binary tree and decode the binary tree to get the original N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. Similarly, a binary tree is a rooted tree in which each node has no more than 2 children. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that an N-ary tree can be encoded to a binary tree and this binary tree can be decoded to the original N-nary tree structure.

_Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See following example)._

For example, you may encode the following `3-ary` tree to a binary tree in this way:

![](https://assets.leetcode.com/uploads/2018/10/12/narytreebinarytreeexample.png)

  
**Input:** root = \[1,null,3,2,4,null,5,6\]  

Note that the above is just an example which _might or might not_ work. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

**Constraints:**

*   The height of the n-ary tree is less than or equal to `1000`
*   The total number of nodes is between `[0, 10^4]`
*   Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.  



**Solution:**  

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(!root) return NULL;
        TreeNode* node = new TreeNode(root->val);
        if (root->children.size() == 0) return node;
        node->left = encode(root->children[0]);
        auto ans = node;
        node = node->left;
        for(int i = 1; i < root->children.size(); ++i) {
            node->right = encode(root->children[i]);
            node = node->right;
        }
        return ans;
    }
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(!root) return NULL;
        Node* node = new Node(root->val);
        if(root->left) node->children.push_back(decode(root->left));
        root = root->left;
        while(root && root->right) {
            node->children.push_back(decode(root->right));
            root = root->right;
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
```
      