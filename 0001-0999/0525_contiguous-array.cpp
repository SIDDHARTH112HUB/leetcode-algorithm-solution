//Link: https://leetcode.com/problems/contiguous-array/ 
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> m;
        m[0] = -1;
        int sum = 0, ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += (nums[i] == 1 ? 1 : -1);
            if(m.count(sum)) {
                ans = max(ans, i - m[sum]);
            }
            if(m.count(sum) == 0)
                m[sum] = i;
        }
        return ans;
    }
};