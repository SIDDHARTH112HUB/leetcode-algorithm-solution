//Link: https://leetcode.com/problems/partition-list/ 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode *l=&left, *r = &right;
        while(head){
            ListNode* &node = head->val<x?l:r;
            node->next = head;
            node = head;
            head = head->next;
        }
        l->next = right.next;
        r->next = nullptr;
        return left.next;
    }
};