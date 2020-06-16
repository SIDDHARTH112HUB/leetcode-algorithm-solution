[143.reorder-list](https://leetcode.com/problems/reorder-list/)  

Given a singly linked list _L_: _L_0→_L_1→…→_L__n_\-1→_L_n,  
reorder it to: _L_0→_L__n_→_L_1→_L__n_\-1→_L_2→_L__n_\-2→…

You may **not** modify the values in the list's nodes, only nodes itself may be changed.

**Example 1:**

  
Given 1->2->3->4, reorder it to 1->4->2->3.

**Example 2:**

  
Given 1->2->3->4->5, reorder it to 1->5->2->4->3.  



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
```
      