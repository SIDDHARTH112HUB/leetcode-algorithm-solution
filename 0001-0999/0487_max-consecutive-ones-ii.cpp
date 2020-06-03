//Link: https://leetcode.com/problems/max-consecutive-ones-ii/ 
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> arr(2);
        bool flip = false;
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                ++arr[flip];
                flip = !flip;
                arr[flip] = 0;
            }
            else ++arr[flip];
            ans = max(ans, arr[0] + arr[1]);
        }
        return ans;
    }
};