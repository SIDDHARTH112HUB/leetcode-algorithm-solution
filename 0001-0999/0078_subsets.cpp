//Link: https://leetcode.com/problems/subsets/ 
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<int> item;
        if( nums.size() == 0 ) return {{}};
        ans.push_back({});
        dfs(nums, 0, item);
        return ans;
    }
    void dfs(vector<int> nums, int idx, vector<int>& item ){
        int size = nums.size();
        if( size == idx ){
            return;
        }
        if( size < idx ) return ;
        item.push_back(nums[idx]);
        ans.push_back(item);
        dfs(nums, idx+1, item);
        item.pop_back();
        dfs(nums, idx+1, item);
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if( nums.size() == 0 ) return {};
        int n = 1<<(nums.size());
        vector<vector<int>> ans;
        for( int i = 0; i<n; i++){
            int j = i;
            vector<int> item;
            int idx = 0;
            while( j> 0){
                if( j&1 )
                    item.push_back(nums[idx]);
                j = j>>1;
                idx++;
            }
            ans.push_back(item);
        }
        return ans;
    }
};