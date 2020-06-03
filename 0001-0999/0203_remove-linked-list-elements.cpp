//Link: https://leetcode.com/problems/remove-linked-list-elements/ 
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
    ListNode* removeElements(ListNode* head, int val) {
        if( head == nullptr ) return head;
        while( head && head->val == val )
            head = head->next;
        if( head == nullptr ) return head;
        auto *prev = head;
        auto *cur  = head->next;
        while( prev && cur ){
            if( cur->val == val){
                prev->next = cur->next;
                cur = prev->next;
            }
            else{
                prev = prev->next;
                cur = cur->next;
            }
        }
        return head;
    }
};