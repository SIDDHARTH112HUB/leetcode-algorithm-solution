//Link: https://leetcode.com/problems/sliding-window-maximum/ 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for( int i = 0; i < nums.size(); i++){
            while( dq.size() && nums[dq.back()] < nums[i] ) dq.pop_back();
            dq.push_back( i );
            while( dq.size() && ( dq.front() < i-k+1  ) ) dq.pop_front();
            if( dq.size() && i >= k -1 ) ans.push_back( nums[dq.front()] );
        }
        return ans;
    }
};