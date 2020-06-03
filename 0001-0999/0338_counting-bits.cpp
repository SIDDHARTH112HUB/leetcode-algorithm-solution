//Link: https://leetcode.com/problems/counting-bits/ 
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans = {0};
        while(ans.size() <= num) {
            int cnt = ans.size();
            for(int i = 0; i < cnt && ans.size() <= num; ++i)
                ans.push_back(ans[i] + 1);
        }
        return ans;
    }
};