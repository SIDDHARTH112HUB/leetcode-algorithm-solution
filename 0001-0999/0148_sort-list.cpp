//Link: https://leetcode.com/problems/sort-list/ 
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
    ListNode* sortList(ListNode* head) {
        if( !head ) return head;
        vector<ListNode*> vec;
        auto node = head;
        while(node){
            vec.push_back(node);
            node = node->next;
        }
        sort(vec.begin(), vec.end(), [](ListNode* a, ListNode* b){
            return a->val < b->val;
        });
        ListNode* dummy = new ListNode(0);
        node = dummy;
        for( auto n: vec){
            node->next = n;
            node = node->next;
        }
        node->next = NULL;
        node = dummy->next;
        delete dummy;
        return node;
    }
};