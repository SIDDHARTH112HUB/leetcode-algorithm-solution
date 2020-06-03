//Link: https://leetcode.com/problems/beautiful-arrangement/ 
class Solution {
public:
    int ans;
    int countArrangement(int N) {
        ans = 0;
        vector<int> nums;
        for( int i = 1; i<=N;i++)
            nums.push_back(i);
        dfs(nums, 0);
        return ans;
    }
    void dfs(vector<int> &nums, int idx ){
        if( idx == nums.size()){
            ans++;
            return;
        }
        for( int i = 0; i<nums.size(); i++){
            if( nums[i] == 0 )
                continue;
            if( nums[i] % (idx+1) == 0 || (idx+1)%nums[i] == 0 ){
                int src = nums[i];
                nums[i] = 0;
                dfs(nums, idx+1);
                nums[i] = src;
            }
        }
    }
};