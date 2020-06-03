//Link: https://leetcode.com/problems/middle-of-the-linked-list/ 
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
    ListNode* middleNode(ListNode* head) {
        if( head == NULL ) return NULL;
        int cnt = 0;
        auto node = head;
        while(node){
            cnt++;
            node = node->next;
        }
        int mid = cnt/2;
        node = head;
        while(mid-->0){
            node = node->next;
        }
        return node;
    }
};