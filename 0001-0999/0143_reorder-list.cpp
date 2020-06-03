//Link: https://leetcode.com/problems/reorder-list/ 
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
    void reorderList(ListNode* head) {
        if( !head || !(head->next) ) return;
        ListNode *node = head;
        deque<ListNode*> dq;
        while( node ){
            dq.push_back(node);
            node = node->next;
        }
        node = head;
        dq.pop_front();
        while(dq.size() ){
            node->next = dq.back();
            node = node->next;
            dq.pop_back();
            if( dq.size() > 0 ){
                node->next = dq.front();
                node = node->next;
                dq.pop_front();
            }
        }
        node->next = NULL;
    }
};