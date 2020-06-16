[148.sort-list](https://leetcode.com/problems/sort-list/)  

Sort a linked list in _O_(_n_ log _n_) time using constant space complexity.

**Example 1:**

  
**Input:** 4->2->1->3
  
**Output:** 1->2->3->4
  

**Example 2:**

  
**Input:** -1->5->3->4->0
  
**Output:** -1->0->3->4->5  



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
    ListNode* sortList(ListNode* head) {
        if( !head ) return head;
        vector<ListNode*> vec;
        auto node = head;
        while(node){
            vec.push_back(node);
            node = node->next;
        }
        sort(vec.begin(), vec.end(), [](ListNode* a, ListNode* b){
            return a->val < b->val;
        });
        ListNode* dummy = new ListNode(0);
        node = dummy;
        for( auto n: vec){
            node->next = n;
            node = node->next;
        }
        node->next = NULL;
        node = dummy->next;
        delete dummy;
        return node;
    }
};
```
      