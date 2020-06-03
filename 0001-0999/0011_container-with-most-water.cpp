//Link: https://leetcode.com/problems/container-with-most-water/ 
class Solution {
public:
    int maxArea(vector<int>& height) {
        if( height.size() <= 1 ) return 0;
        int ans = 0;
        int l = 0, r=height.size()-1;
        while( l < r ){
            ans = max( ans, (r-l)*min(height[r], height[l]) );
            height[r] > height[l]?++l:--r;
        }
        return ans;
    }
};