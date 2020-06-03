//Link: https://leetcode.com/problems/rotate-list/ 
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
    ListNode* rotateRight(ListNode* head, int k) {
        if( k == 0 ) return head;
        if( !head ) return head;
        int cnt = 0;
        
        auto node = head;
        auto last = node;
        
        while(node ){
            last = node;
            node = node->next;
            cnt++;
        }
        node = head;
        k = cnt - k %cnt;
        auto prev = head;
        if( k == cnt ) return head;
        while(node){
            prev = node;
            node = node->next;
            k--;
            if( k == 0 )
                break;
        }
        last->next = head;
        prev->next = NULL;
        return node;    
    }
};