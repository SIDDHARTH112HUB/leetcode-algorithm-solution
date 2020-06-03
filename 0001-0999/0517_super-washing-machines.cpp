//Link: https://leetcode.com/problems/super-washing-machines/ 
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if( sum % machines.size()) return -1;
        int avg = sum / machines.size();
        int res = 0, prev = 0;
        for(auto n : machines) {
            int diff = n - avg;
            if(diff) {
                prev += diff;
            }
            res = max(res, max(abs(prev), n-avg));
        }
        return res;
    }
};