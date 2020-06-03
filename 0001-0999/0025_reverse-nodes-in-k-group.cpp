//Link: https://leetcode.com/problems/reverse-nodes-in-k-group/ 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k <= 1) return head;
        ListNode* ans = NULL, *prev=NULL, *prev1=NULL;
        auto next = head;
        stack<ListNode*> stk;
        while( next ){
            stk.push(next);
            next = next->next;
            if( stk.size() >= k  ){
                prev = stk.top();
                if( !ans ) ans = prev;
                if( prev1 )
                    prev1->next = prev;
                stk.pop();
                while( stk.size() ){
                    prev->next = stk.top();
                    stk.pop();
                    prev = prev->next;
                    if( stk.size()==0 && !next )
                        prev->next = NULL;
                }
                prev1 = prev;
            }else if( !next ){
                ListNode* first = NULL;
                while(stk.size()){
                    first = stk.top();
                    stk.pop();
                }
                if( prev1 )
                    prev1->next = first;
            }
        }
        
        return ans?ans:head;
    }
};