[61.rotate-list](https://leetcode.com/problems/rotate-list/)  

Given a linked list, rotate the list to the right by _k_ places, where _k_ is non-negative.

**Example 1:**

**Input:** 1->2->3->4->5->NULL, k = 2
**Output:** 4->5->1->2->3->NULL
**Explanation:**
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

**Example 2:**

**Input:** 0->1->2->NULL, k = 4
**Output:** `2->0->1->NULL`
**Explanation:**
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: `0->1->2->NULL`
rotate 4 steps to the right: `2->0->1->NULL`  



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
    ListNode* rotateRight(ListNode* head, int k) {
        if( k == 0 ) return head;
        if( !head ) return head;
        int cnt = 0;
        
        auto node = head;
        auto last = node;
        
        while(node ){
            last = node;
            node = node->next;
            cnt++;
        }
        node = head;
        k = cnt - k %cnt;
        auto prev = head;
        if( k == cnt ) return head;
        while(node){
            prev = node;
            node = node->next;
            k--;
            if( k == 0 )
                break;
        }
        last->next = head;
        prev->next = NULL;
        return node;    
    }
};
```
      