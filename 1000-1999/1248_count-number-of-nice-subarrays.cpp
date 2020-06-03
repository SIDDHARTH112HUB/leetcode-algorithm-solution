//Link: https://leetcode.com/problems/count-number-of-nice-subarrays/ 
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0, j = 0, cnt = 0;
        vector<int> arr = {-1};
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] % 2)
                arr.push_back(i);
        }
        arr.push_back(nums.size());
        if(arr.size() < k+2) return 0;
        int ans = 0;
        for(int i = k; i < arr.size()-1; ++i){
            ans += (arr[i + 1] - arr[i]) * (arr[i - k+1] - arr[i - k]);
        }
        return ans;
    }
};