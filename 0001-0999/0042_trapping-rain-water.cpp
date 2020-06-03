//Link: https://leetcode.com/problems/trapping-rain-water/ 
class Solution {
public:
    int trap(vector<int>& height) {
        if( height.size() <= 2 ) return 0;
        int ans = 0;
        int limit = 0, low = 0, l = 0, r = height.size()-1;
        while( l < r){
            low = height[l]< height[r]? height[l++]:height[r--];
            limit = max(limit, low);
            ans += limit - low;
        }
        return ans;
    }
};