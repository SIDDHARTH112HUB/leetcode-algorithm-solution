[142.linked-list-cycle-ii](https://leetcode.com/problems/linked-list-cycle-ii/)  

Given a linked list, return the node where the cycle begins. If there is no cycle, return `null`.

To represent a cycle in the given linked list, we use an integer `pos` which represents the position (0-indexed) in the linked list where tail connects to. If `pos` is `-1`, then there is no cycle in the linked list.

**Note:** Do not modify the linked list.

**Example 1:**

  
**Input:** head = \[3,2,0,-4\], pos = 1  
**Output:** tail connects to node index 1  
**Explanation:** There is a cycle in the linked list, where tail connects to the second node.  

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist.png)

**Example 2:**

  
**Input:** head = \[1,2\], pos = 0  
**Output:** tail connects to node index 0  
**Explanation:** There is a cycle in the linked list, where tail connects to the first node.  

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test2.png)

**Example 3:**

  
**Input:** head = \[1\], pos = -1  
**Output:** no cycle  
**Explanation:** There is no cycle in the linked list.  

![](https://assets.leetcode.com/uploads/2018/12/07/circularlinkedlist_test3.png)

**Follow-up**:  
Can you solve it without using extra space?  



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
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        while( fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if( slow == fast )
                break;
        }
        if( !fast || !fast->next ) return NULL;
        slow = head;
        while( slow != fast ){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
```
      