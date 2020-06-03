//Link: https://leetcode.com/problems/degree-of-an-array/ 
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, pair<int, int> > pos;
        int len = 0, ans=INT_MAX;
        for( int i = 0; i < nums.size(); i++ ){
            int n = nums[i];
            if( ++m[n] ==1 ){
                pos[n] = {i, i};
            }else
                pos[n].second = i;
            len = max(len, m[n]);
        }
        for( auto it : m ){
            if( it.second == len ){
                ans = min( ans, pos[it.first].second - pos[it.first].first + 1);
            }
        }
        return ans;
        /*
        int left = 0, right = nums.size() - 1;
        while(left <= right ){
            right = nums.size() - 1;
            while(left < nums.size() && m[nums[left]] != len ) left++;
            while(left < nums.size() && right >=0 && nums[right] != nums[left] ) right--;
            if( left <= right ){
                ans = min(ans, right-left+1);
                m[nums[left]] = -1;
            }
            
        }
        return ans;*/
    }
};