[86.partition-list](https://leetcode.com/problems/partition-list/)  

Given a linked list and a value _x_, partition it such that all nodes less than _x_ come before nodes greater than or equal to _x_.

You should preserve the original relative order of the nodes in each of the two partitions.

**Example:**

  
**Input:** head = 1->4->3->2->5->2, _x_ = 3
  
**Output:** 1->2->2->4->3->5  



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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0), right(0);
        ListNode *l=&left, *r = &right;
        while(head){
            ListNode* &node = head->val<x?l:r;
            node->next = head;
            node = head;
            head = head->next;
        }
        l->next = right.next;
        r->next = nullptr;
        return left.next;
    }
};
```
      