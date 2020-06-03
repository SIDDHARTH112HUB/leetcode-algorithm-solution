//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/ 
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
        if( !head ) return head;
        if( !head->next ) return head;
        /*ListNode* node = head;

        while( node->next ){
            if( node->val == node->next->val){
                head = node->next->next;
                node=node->next;
            }else
                break;
        }
        if(!head ) return NULL;
        node = head;
        cout<<"head val"<<head->val<<endl;
        ListNode *next = node;
        while(next){
            if( next->next && next->val == next->next->val ){
                next = next->next;
            }else{
                node->next = next->next;
                node = node->next;
                next = next->next;
            }
        }
        return head;*/
        
        ListNode* prev = head;
        ListNode* next = head->next;
        ListNode* node = NULL;
        head = NULL;
        int cnt = 0;
        //cout<<"begin"<<endl;
        while( prev ){
            next = prev->next?prev->next:prev;
            if( prev->val != next->val || prev == next){
                if( cnt == 0 ){
                    //cout<<"add prev "<< prev->val<<endl;
                    if( !head ){
                        head = prev;
                        node = head;
                    }else{
                        node->next = prev;
                        node = node->next;
                    }
                    
                }
                if( next == prev){
                    if(node)
                        node->next = NULL;
                    break;
                }
                prev = next;
                next = next->next;
                //prev->next = NULL;
                cnt = 0;
            }else{
                cnt++;
                if( next == prev)
                    break;
                prev = next;
                next = next->next;
            }
        }
        return head;
    }
};