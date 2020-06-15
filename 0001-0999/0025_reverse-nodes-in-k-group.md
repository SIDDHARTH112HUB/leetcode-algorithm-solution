[25.reverse-nodes-in-k-group](https://leetcode.com/problems/reverse-nodes-in-k-group/)  

Given a linked list, reverse the nodes of a linked list _k_ at a time and return its modified list.

_k_ is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of _k_ then left-out nodes in the end should remain as it is.

**Example:**

Given this linked list: `1->2->3->4->5`

For _k_ = 2, you should return: `2->1->4->3->5`

For _k_ = 3, you should return: `3->2->1->4->5`

**Note:**

*   Only constant extra memory is allowed.
*   You may not alter the values in the list's nodes, only nodes itself may be changed.  



**Solution:**  

```cpp
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
```
      