//Link: https://leetcode.com/problems/swap-nodes-in-pairs/ 
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
    ListNode* swapPairs(ListNode* head) {
        if( !head ) return head;
        if( !head->next ) return head;
        auto first = head;
        auto second = head->next;
        head=head->next;
        ListNode* prev = NULL;
        while(second){
            
            auto third = second->next;
            second->next = first;
            first->next = third;
            if( prev )
                prev->next = second;
            prev = first;
            first = third;
            second = third?third->next:NULL;
        }
        return head;
    }
};