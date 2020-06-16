[19.remove-nth-node-from-end-of-list](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)  

Given a linked list, remove the _n_\-th node from the end of list and return its head.

**Example:**

  
Given linked list: **1->2->3->4->5**, and **_n_ = 2**.
  

  
After removing the second node from the end, the linked list becomes **1->2->3->5**.
  

**Note:**

Given _n_ will always be valid.

**Follow up:**

Could you do this in one pass?  



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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if( !head ) return NULL;
        int len = 1;
        auto next = head;
        while(next=next->next)len++;
        if( len <= n )
            return head->next;
        next = head;
        auto prev = next;
        while(n++<len){
            prev = next;
            next=next->next;
        }
        prev->next = next->next;
        return head;
    }
};
```
      