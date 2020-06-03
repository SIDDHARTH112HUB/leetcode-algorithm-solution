//Link: https://leetcode.com/problems/insertion-sort-list/ 
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
    ListNode* insertionSortList(ListNode* head) {
        auto src = head, dummy = new ListNode(-1);
        
        while( src ){
            auto des = dummy, cur = src;
            while( des && des->next && cur->val > des->next->val ){
                des = des->next;
            }
            src = src->next;
            if( des ){
                cur->next = des->next;
                des->next = cur;
            }
            
            
        }
        return dummy->next;
    }
};