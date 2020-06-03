//Link: https://leetcode.com/problems/range-addition-ii/ 
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int height=m, width = n;
        for( auto &op: ops){
            height = min(height, op[0]);
            width = min(width, op[1]);
        }
        return height*width;
    }
};