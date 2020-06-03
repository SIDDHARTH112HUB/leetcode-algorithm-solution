//Link: https://leetcode.com/problems/odd-even-linked-list/ 
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        auto oddHead = head;
        auto evenHead= head->next;
        if( evenHead == NULL || evenHead->next==NULL)
            return oddHead;
        auto evenNext = evenHead;
        auto oddNext = oddHead;
        while( evenNext && evenNext->next ){
            oddNext->next = evenNext->next;
            oddNext = oddNext->next;
            evenNext->next = oddNext->next;
            evenNext = evenNext->next;
        }
        oddNext->next = evenHead;
        return oddHead;
    }
};