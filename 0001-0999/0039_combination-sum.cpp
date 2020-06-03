//Link: https://leetcode.com/problems/combination-sum/ 
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //if( candidates.size() =--
        vector<int> item;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, item);
        return ans;
    }
    void dfs(vector<int> &nums, int target, int idx, vector<int> &item){
        if( target == 0 ){
            ans.push_back(item);
            return;
        }
        if( target<0)
            return;
        if( idx >= nums.size() )
            return;
        
        int n = nums[idx];
        if( target-n < 0 )
            return;
        item.push_back(n);
        dfs(nums, target-n, idx, item);
        item.pop_back();
        dfs(nums, target, idx+1, item);
    }
    
};