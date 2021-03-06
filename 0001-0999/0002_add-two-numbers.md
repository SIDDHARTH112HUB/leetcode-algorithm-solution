[2.add-two-numbers](https://leetcode.com/problems/add-two-numbers/)  

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example:**

  
**Input:** (2 -> 4 -> 3) + (5 -> 6 -> 4)
  
**Output:** 7 -> 0 -> 8
  
**Explanation:** 342 + 465 = 807.  



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if( !l1) return l2;
        if( !l2 ) return l1;
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* next = dummy;
        while( l1 || l2 || carry){
            int sum = 0;
            if( l1  ){
                sum += l1->val;
                l1 = l1->next;
            }
            if( l2  ){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum /10;
            sum = sum %10;
            next->next = new ListNode(sum);
            next = next->next;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};
```
      