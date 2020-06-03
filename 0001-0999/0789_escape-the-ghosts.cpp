//Link: https://leetcode.com/problems/escape-the-ghosts/ 
class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int step = abs(target[0])+abs(target[1]);
        for( auto &g:ghosts){
            int gstep = abs(g[0] - target[0]) + abs(g[1] - target[1]);
            if( gstep <= step )
                return false;
        }
        return true;
    }
};