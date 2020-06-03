//Link: https://leetcode.com/problems/linked-list-in-binary-tree/ 
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(h(head, root)) return true;
        if(!head) return true;
        if(!root) return false;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
    
    bool h(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        if(head->val != root->val ) return false;
        return h(head->next, root->left) || h(head->next, root->right);
    }
};