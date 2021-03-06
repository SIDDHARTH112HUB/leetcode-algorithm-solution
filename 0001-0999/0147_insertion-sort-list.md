[147.insertion-sort-list](https://leetcode.com/problems/insertion-sort-list/)  

Sort a linked list using insertion sort.

![](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)  
A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.  
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list  
 

**Algorithm of Insertion Sort:**

1.  Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2.  At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3.  It repeats until no input elements remain.

  
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
    ListNode* insertionSortList(ListNode* head) {
        auto src = head, dummy = new ListNode(-1);
        
        while( src ){
            auto des = dummy, cur = src;
            while( des && des->next && cur->val > des->next->val ){
                des = des->next;
            }
            src = src->next;
            if( des ){
                cur->next = des->next;
                des->next = cur;
            }
            
            
        }
        return dummy->next;
    }
};
```
      