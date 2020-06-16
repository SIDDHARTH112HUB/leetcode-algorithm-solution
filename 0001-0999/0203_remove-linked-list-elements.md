[203.remove-linked-list-elements](https://leetcode.com/problems/remove-linked-list-elements/)  

Remove all elements from a linked list of integers that have value **_val_**.

**Example:**

  
**Input:**  1->2->6->3->4->5->6, _**val**_ = 6
  
**Output:** 1->2->3->4->5  



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
    ListNode* removeElements(ListNode* head, int val) {
        if( head == nullptr ) return head;
        while( head && head->val == val )
            head = head->next;
        if( head == nullptr ) return head;
        auto *prev = head;
        auto *cur  = head->next;
        while( prev && cur ){
            if( cur->val == val){
                prev->next = cur->next;
                cur = prev->next;
            }
            else{
                prev = prev->next;
                cur = cur->next;
            }
        }
        return head;
    }
};
```
      