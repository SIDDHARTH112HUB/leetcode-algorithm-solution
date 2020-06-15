//Link: https://leetcode.com/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        auto node = head;
        int i = m - 1, j = n;
        while(node) {
            if(i == 0) {
                if(!node->next) return head;
                node->next = node->next->next;
                --j;
            }else{
                node = node->next;
                --i;
            }
            if(j == 0 && i == 0) {
                i = m;
                j = n;
            }
        }
        return head;
    }
};