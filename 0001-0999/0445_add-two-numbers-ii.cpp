//Link: https://leetcode.com/problems/add-two-numbers-ii/ 
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
        stack<int> s1, s2, s3;
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* dummy = new ListNode(0);
        int c = 0;
        while(s1.size() || s2.size() || c){
            int a = s1.size() ? s1.top() : 0;
            int b = s2.size() ? s2.top() : 0;
            s3.push((a+b+c) % 10) ;
            c = (a+b+c) / 10;
            if(s1.size()) s1.pop();
            if(s2.size()) s2.pop();
        }
        auto node = dummy;
        while(s3.size()) {
            node->next = new ListNode(s3.top());
            s3.pop();
            node = node->next;
        }
        return dummy->next;
    }
};