[1171.remove-zero-sum-consecutive-nodes-from-linked-list](https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)  

Given the `head` of a linked list, we repeatedly delete consecutive sequences of nodes that sum to `0` until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

(Note that in the examples below, all sequences are serializations of `ListNode` objects.)

**Example 1:**

  
**Input:** head = \[1,2,-3,3,1\]  
**Output:** \[3,1\]  
**Note:** The answer \[1,2,1\] would also be accepted.  

**Example 2:**

  
**Input:** head = \[1,2,3,-3,4\]  
**Output:** \[1,2,4\]  

**Example 3:**

  
**Input:** head = \[1,2,3,-3,-2\]  
**Output:** \[1\]  

**Constraints:**

*   The given linked list will contain between `1` and `1000` nodes.
*   Each node in the linked list has `-1000 <= node.val <= 1000`.  



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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<pair<int, int> > v;
        unordered_map<int, int> m;
        //m[0] = 1;
        while(head) {
            int sum = ((v.size()? v.back().first : 0) + head->val);
            if(sum == 0) {
                v = {};
                head = head->next;
                m = {};
                continue;
            }
            if(m.count(sum)) {
                while(v.size() && sum != v.back().first) {
                    auto p = v.back();
                    int s = p.first;
                    int n = p.second;
                    m.erase(s);
                    v.pop_back();
                    //sum -= n;
                }
            }else{
                v.push_back({sum, head->val});
                m[sum] = 1;
            }
            head = head->next;
        }
        ListNode* d = new ListNode(0);
        auto node = d;
        for(auto n : v ){
            node->next = new ListNode(n.second);
            node = node->next;
            //cout<<n.second<<" ";
        }
        //cout<<endl;
        return d->next;
    }
};
```
      