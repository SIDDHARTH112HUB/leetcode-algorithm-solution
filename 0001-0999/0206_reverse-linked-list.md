[206.reverse-linked-list](https://leetcode.com/problems/reverse-linked-list/)  

Reverse a singly linked list.

**Example:**

  
**Input:** 1->2->3->4->5->NULL
  
**Output:** 5->4->3->2->1->NULL
  

**Follow up:**

A linked list can be reversed either iteratively or recursively. Could you implement both?  



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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while(head) {
            auto next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
```
      