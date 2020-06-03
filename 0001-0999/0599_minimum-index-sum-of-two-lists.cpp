//Link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/ 
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int mn = INT_MAX;
        vector<string> ans;
        for(int i = 0; i < list1.size(); ++i) {
            for(int j = 0; j < list2.size(); ++j) {
                if(list1[i] == list2[j] && i + j <= mn) {
                    if(i + j < mn) {
                        ans = {};
                        mn = i + j;
                    }
                    ans.push_back(list1[i]);
                }
            }
        }
        return ans;
    }
};