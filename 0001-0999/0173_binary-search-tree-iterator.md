[173.binary-search-tree-iterator](https://leetcode.com/problems/binary-search-tree-iterator/)  

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling `next()` will return the next smallest number in the BST.

**Example:**

**![](https://assets.leetcode.com/uploads/2018/12/25/bst-tree.png)**

  
BSTIterator iterator = new BSTIterator(root);
  
iterator.next();    // return 3
  
iterator.next();    // return 7
  
iterator.hasNext(); // return true
  
iterator.next();    // return 9
  
iterator.hasNext(); // return true
  
iterator.next();    // return 15
  
iterator.hasNext(); // return true
  
iterator.next();    // return 20
  
iterator.hasNext(); // return false
  

**Note:**

*   `next()` and `hasNext()` should run in average O(1) time and uses O(_h_) memory, where _h_ is the height of the tree.
*   You may assume that `next()` call will always be valid, that is, there will be at least a next smallest number in the BST when `next()` is called.  



**Solution:**  

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    //TreeNode* root;
    stack<TreeNode*> stk;
    BSTIterator(TreeNode *root) {
        //this->root = root;
        while(root){
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stk.size()>0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        int val = node->val;
        node = node->right;
        while(node){
            stk.push(node);
            node = node->left;
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
```
      