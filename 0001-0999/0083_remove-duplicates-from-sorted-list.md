[83.remove-duplicates-from-sorted-list](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)  

Given a sorted linked list, delete all duplicates such that each element appear only _once_.

**Example 1:**

**Input:** 1->1->2
**Output:** 1->2

**Example 2:**

**Input:** 1->1->2->3->3
**Output:** 1->2->3  



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
    ListNode* deleteDuplicates(ListNode* head) {
        auto next = head;
        while(next && next->next){
            if( next->val == next->next->val)
                next->next = next->next->next;
            else{
                next=next->next;
            }
            if(!next)break;
        }
        return head;
    }
};
```
      