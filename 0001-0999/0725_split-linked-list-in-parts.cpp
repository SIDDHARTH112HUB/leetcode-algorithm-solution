//Link: https://leetcode.com/problems/split-linked-list-in-parts/ 
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        auto node = root;
        int size = 0;
        while(node) {
            ++size;
            node = node->next;
        }
        node = root;
        vector<ListNode*> ans(k);
        int cnt = size / k;
        while(k && node) {
            ans[k - 1] = node;
            int c = cnt + (size % k > 0);
            auto prev = node;
            while(c-- > 0 && node) {
                prev = node;
                node = node->next;
                --size;
            }
            if(prev) prev->next = NULL;
            --k;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
