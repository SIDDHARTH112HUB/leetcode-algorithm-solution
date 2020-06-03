//Link: https://leetcode.com/problems/random-pick-index/ 
class Solution {
public:
    vector<int> arr;
    Solution(vector<int> nums): arr(nums) {
    }
    
    int pick(int target) {
        int res = -1, cnt = 0;
        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] != target) continue;
            if(rand() % (++cnt) == 0) res = i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */