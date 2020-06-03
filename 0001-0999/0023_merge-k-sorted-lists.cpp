//Link: https://leetcode.com/problems/merge-k-sorted-lists/ 
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
    struct cmp{
       bool operator()(ListNode* &a, ListNode* &b){
           return a->val > b->val;
       } 
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode*, vector<ListNode*>, cmp> pq;
        for(ListNode* p: lists){
            if( p)
                pq.push(p);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while( pq.size() ){
            auto n = pq.top();
            pq.pop();
            node->next = n;
            node = node->next;
            if( n->next )
                pq.push(n->next);
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};