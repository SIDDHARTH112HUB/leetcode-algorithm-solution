//Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head) {
            ans <<= 1;
            ans |= head->val;
            head = head->next;
        }
        return ans;
    }
};