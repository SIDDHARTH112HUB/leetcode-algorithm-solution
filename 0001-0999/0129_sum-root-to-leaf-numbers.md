[129.sum-root-to-leaf-numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers/)  

Given a binary tree containing digits from `0-9` only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path `1->2->3` which represents the number `123`.

Find the total sum of all root-to-leaf numbers.

**Note:** A leaf is a node with no children.

**Example:**

  
**Input:** \[1,2,3\]
  
    1
  
   / \\
  
  2   3
  
**Output:** 25
  
**Explanation:**
  
The root-to-leaf path `1->2` represents the number `12`.
  
The root-to-leaf path `1->3` represents the number `13`.
  
Therefore, sum = 12 + 13 = `25`.

**Example 2:**

  
**Input:** \[4,9,0,5,1\]
  
    4
  
   / \\
  
  9   0
  
 / \\
  
5   1
  
**Output:** 1026
  
**Explanation:**
  
The root-to-leaf path `4->9->5` represents the number 495.
  
The root-to-leaf path `4->9->1` represents the number 491.
  
The root-to-leaf path `4->0` represents the number 40.
  
Therefore, sum = 495 + 491 + 40 = `1026`.  



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
class Solution {
public:
    int cal(TreeNode* node, int num, int& sum){
        if( node == NULL ) return num;
        int new_num = num*10 + node->val;
        if( node->left == NULL && node->right == NULL ){
            sum = sum + new_num;
            return new_num;
        }
        int r = 0;
        if( node->left != NULL )
            r = cal( node->left, new_num, sum);
        if( node->right != NULL )
            r = cal( node->right, new_num, sum);
        return r;
    }
    int sumNumbers(TreeNode *root) {
        if( root == NULL ) return 0;
        int sum = 0;
        cal( root, 0, sum);
        return sum;
    }
};
```
      