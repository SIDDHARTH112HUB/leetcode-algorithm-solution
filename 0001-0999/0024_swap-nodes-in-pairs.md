[24.swap-nodes-in-pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)  

Given a linked list, swap every two adjacent nodes and return its head.

You may **not** modify the values in the list's nodes, only nodes itself may be changed.

**Example:**

  
Given `1->2->3->4`, you should return the list as `2->1->4->3`.  



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
    ListNode* swapPairs(ListNode* head) {
        if( !head ) return head;
        if( !head->next ) return head;
        auto first = head;
        auto second = head->next;
        head=head->next;
        ListNode* prev = NULL;
        while(second){
            
            auto third = second->next;
            second->next = first;
            first->next = third;
            if( prev )
                prev->next = second;
            prev = first;
            first = third;
            second = third?third->next:NULL;
        }
        return head;
    }
};
```
      