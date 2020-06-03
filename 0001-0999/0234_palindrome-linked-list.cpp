//Link: https://leetcode.com/problems/palindrome-linked-list/ 
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
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode *next = head;
        while(next){
            count++;
            next=next->next;
        }
        if( count <= 1 ) return true;
        if( count == 2 ){
            return head->val == head->next->val;
        }
        if( count == 3 ){
            return head->val == head->next->next->val;
        }
        int mid = count/2;
        int m = mid + count%2;
        next = head;
        while(m-->0){
            next = next->next;
        }
        ListNode* prev = nullptr;
        ListNode* nextnext = nullptr;
        ListNode* reverse = nullptr;
        while( next ){
            //printf("search half %d %d\n", next->val);
            nextnext = next->next;
            next->next = prev;
            prev = next;
            if( nextnext )
                reverse = nextnext;
            next = nextnext;
        }
        nextnext = reverse;
        while( nextnext && head ){
            if( nextnext->val !=head->val )
                return false;
            nextnext = nextnext->next;
            head = head->next;
        }
        return true;
    }
};