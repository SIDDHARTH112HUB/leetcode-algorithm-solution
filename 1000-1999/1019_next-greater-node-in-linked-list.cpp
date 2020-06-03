//Link: https://leetcode.com/problems/next-greater-node-in-linked-list/ 
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
    vector<int> nextLargerNodes(ListNode* head) {
        if (!head ) return {};
        vector<int> ans = {0};
        vector<int> nums, tail;
        ListNode* tmp = head;
        while (tmp) {
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
        reverse(nums.begin(), nums.end());
        tail.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            while(tail.size()) {
                if (n >= tail.back())
                    tail.pop_back();
                else
                    break;
            }
            if( tail.size()>0)
                ans.push_back(tail.back());
            else
                ans.push_back(0);
            tail.push_back(n);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};