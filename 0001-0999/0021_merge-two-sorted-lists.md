[21.merge-two-sorted-lists](https://leetcode.com/problems/merge-two-sorted-lists/)  

Merge two sorted linked lists and return it as a new **sorted** list. The new list should be made by splicing together the nodes of the first two lists.

**Example:**

**Input:** 1->2->4, 1->3->4
**Output:** 1->1->2->3->4->4  



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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while(l1 || l2){
            ListNode** next = l1?&l1:&l2;
            if( l1 && l2 ){
                if(l1->val > l2->val ){
                    next = &l2;
                }else{
                    next = &l1;
                }
            }
            node->next = *next;
            node = node->next;
            *next = (*next)->next;
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};
```
      