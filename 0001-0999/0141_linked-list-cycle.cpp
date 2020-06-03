//Link: https://leetcode.com/problems/linked-list-cycle/ 
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
    bool hasCycle(ListNode *head) {
        if(head == NULL ) return false;
        if(head->next == NULL) return false;
        ListNode* p = head;
        ListNode* pp = head->next;
        if( p == pp )return true;
        while( p!= NULL && pp!=NULL){
            p = p->next;
            pp = pp->next;
            if( p == NULL || pp == NULL ) return false;
            if( p == pp ) return true;
            pp = pp->next;
            if( pp == NULL ) return false;
            if( p == pp ) return true;
        }
        return true;
    }
};