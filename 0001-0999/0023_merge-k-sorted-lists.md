[23.merge-k-sorted-lists](https://leetcode.com/problems/merge-k-sorted-lists/)  

Merge _k_ sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

**Example:**

  
**Input:**
  
\[
  
  1->4->5,
  
  1->3->4,
  
  2->6
  
\]
  
**Output:** 1->1->2->3->4->4->5->6  



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
    struct cmp{
       bool operator()(ListNode* &a, ListNode* &b){
           return a->val > b->val;
       } 
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode*, vector<ListNode*>, cmp> pq;
        for(ListNode* p: lists){
            if( p)
                pq.push(p);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while( pq.size() ){
            auto n = pq.top();
            pq.pop();
            node->next = n;
            node = node->next;
            if( n->next )
                pq.push(n->next);
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};
```
      