//Link: https://leetcode.com/problems/intersection-of-two-linked-lists/ 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        if( headA == NULL || headB ==NULL )return NULL;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while( pA!=NULL){
            len1++;
            pA = pA->next;
        }
        while( pB != NULL){
            len2++;
            pB = pB->next;
        }
        pB = headB;
        pA = headA;
        
        while( pA!=NULL && pB!=NULL){
            if(len1 > len2){
                pA=pA->next;
                len1--;
            }
            else if(len2>len1){
                pB=pB->next;
                len2--;
            }
            else{
                if( pB==pA ) return pB;
                pB=pB->next;
                pA=pA->next;
                len2--;
                len1--;
            }
        }
        return NULL;
    }
};