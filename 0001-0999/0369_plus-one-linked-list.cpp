//Link: https://leetcode.com/problems/plus-one-linked-list/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int c = 0;
    ListNode* plusOne(ListNode* head) {
        if(!head) return NULL;
        plus(head);
        if(c == 1) {
            auto node = new ListNode(1);
            node->next = head;
            return node;
        }
        return head;
    }
    
    ListNode *plus(ListNode* head) {
        if(head == NULL) {
            c = 1; return NULL;
        }
        plus(head->next);
        if(c == 1) {
            head->val += c;
            c = head->val / 10;
            head->val %= 10;
        }
        return head;
    }
};