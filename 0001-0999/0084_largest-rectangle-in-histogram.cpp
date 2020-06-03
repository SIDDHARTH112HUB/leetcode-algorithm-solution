//Link: https://leetcode.com/problems/largest-rectangle-in-histogram/ 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        auto &h = heights;
        int ans = 0;
        h.push_back(-1);
        stack<pair<int, int> > stk;
        for( int i = 0; i<h.size(); i++){
            while( stk.size() && stk.top().first > h[i]){
                int prev_h = stk.top().first;
                stk.pop();    
                int prev_idx = 0;
                if( stk.size() )
                    prev_idx = stk.top().second+1;
                ans = max( prev_h *(i-prev_idx), ans);
            }
            stk.push({h[i], i});
        }
        h.pop_back();
        return ans;
    }
};