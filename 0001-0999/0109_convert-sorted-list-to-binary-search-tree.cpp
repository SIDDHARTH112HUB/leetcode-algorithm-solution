//Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/ 
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