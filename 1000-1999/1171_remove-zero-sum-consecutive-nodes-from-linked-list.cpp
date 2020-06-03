//Link: https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/ 
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