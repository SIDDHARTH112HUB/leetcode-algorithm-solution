//Link: https://leetcode.com/problems/subsets-ii/ 
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> item;
        dfs(nums, 0, item);
        return ans;
    }
    void dfs(vector<int> &nums, int idx, vector<int> &item){
        int size = nums.size();
        if( idx >= size ){
            ans.push_back(item);
            return;
        }
        int n = nums[idx];
        int upper = upper_bound(nums.begin(), nums.end(), n)-nums.begin();
        for( int i = idx; i<=upper; i++){
            int cnt = i-idx;
            while(cnt-->0)
                item.push_back(n);
            dfs(nums, upper, item);
            cnt = i-idx;
            while( cnt-->0)
                item.pop_back();
        }
    }
};