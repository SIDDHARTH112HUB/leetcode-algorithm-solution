[109.convert-sorted-list-to-binary-search-tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)  

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of _every_ node never differ by more than 1.

**Example:**

Given the sorted linked list: \[-10,-3,0,5,9\],

One possible answer is: \[0,-3,9,-10,null,5\], which represents the following height balanced BST:

      0
     / \\
   -3   9
   /   /
 -10  5  



**Solution:**  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        auto node = head;
        while(node){
            nums.push_back(node->val);
            node = node->next;
        }
        return build(nums, 0, nums.size() - 1 );
    }
    TreeNode* build( vector<int> &nums, int l, int r){
        if( l > r )
            return NULL;
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, l, mid-1);
        node->right = build(nums, mid+1, r);
        return node;
    }
};
```
      