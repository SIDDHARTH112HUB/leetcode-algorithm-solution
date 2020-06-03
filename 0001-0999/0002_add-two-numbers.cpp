//Link: https://leetcode.com/problems/add-two-numbers/ 
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if( !l1) return l2;
        if( !l2 ) return l1;
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* next = dummy;
        while( l1 || l2 || carry){
            int sum = 0;
            if( l1  ){
                sum += l1->val;
                l1 = l1->next;
            }
            if( l2  ){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum /10;
            sum = sum %10;
            next->next = new ListNode(sum);
            next = next->next;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};