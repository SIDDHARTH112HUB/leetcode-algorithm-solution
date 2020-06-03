//Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/ 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( !head ) return NULL;
        int len = 1;
        auto next = head;
        while(next=next->next)len++;
        if( len <= n )
            return head->next;
        next = head;
        auto prev = next;
        while(n++<len){
            prev = next;
            next=next->next;
        }
        prev->next = next->next;
        return head;
    }
};