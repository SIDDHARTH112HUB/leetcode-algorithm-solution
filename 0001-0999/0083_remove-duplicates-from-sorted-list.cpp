//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/ 
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
    ListNode* deleteDuplicates(ListNode* head) {
        auto next = head;
        while(next && next->next){
            if( next->val == next->next->val)
                next->next = next->next->next;
            else{
                next=next->next;
            }
            if(!next)break;
        }
        return head;
    }
};