//Link: https://leetcode.com/problems/linked-list-components/ 
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
    int numComponents(ListNode* head, vector<int>& G) {
        if( !head ) return 0;
        if( !head->next ) return 1;
        map<int, int> G_map;
        for( int i: G )
            G_map[i] = 1;
        int ans = 0;
        while( head && head->next ){
            if( G_map[head->val] && !G_map[head->next->val] )
                ans++;
            else if(!head->next->next && G_map[head->next->val]){
                ans++;
            }
            head = head->next;
        }
        return ans;
    }
};