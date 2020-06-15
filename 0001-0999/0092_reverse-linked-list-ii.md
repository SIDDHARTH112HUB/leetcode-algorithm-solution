[92.reverse-linked-list-ii](https://leetcode.com/problems/reverse-linked-list-ii/)  

Reverse a linked list from position _m_ to _n_. Do it in one-pass.

**Note:** 1 ≤ _m_ ≤ _n_ ≤ length of list.

**Example:**

**Input:** 1->2->3->4->5->NULL, _m_ = 2, _n_ = 4
**Output:** 1->4->3->2->5->NULL  



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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if( m == n )return head;
        stack<ListNode*> s;
        int i=1;
        ListNode* prev = NULL;
        ListNode* tail = NULL;
        ListNode* p = head;
        while(p!=NULL){
            if( m - 1 == i)
                prev = p;
            if( i == n + 1)
                tail = p;
            if( i >= m && i<=n ){
                s.push( p );
            }
            
            i++;
            p = p->next;
        }
        while( s.size() > 0){
            p = s.top();
            s.pop();
            if( prev != NULL ){
                prev->next = p;
            }
            else
                head = p;
            prev = p;
        }
        prev->next = tail;
        return head;
    }
};
```
      