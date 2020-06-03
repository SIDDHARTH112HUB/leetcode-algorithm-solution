//Link: https://leetcode.com/problems/build-an-array-with-stack-operations/ 
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cur = 1;
        
        vector<string> ans;
        vector<int> stk;
        for(int i = 0; i < target.size(); ++i) {
            while(target[i] > cur) {
                stk.push_back(target[i]);
                ans.push_back("Push");
                ans.push_back("Pop");
                ++cur;
            }
            ans.push_back("Push");
            ++cur;
        }
        return ans;
    }
};