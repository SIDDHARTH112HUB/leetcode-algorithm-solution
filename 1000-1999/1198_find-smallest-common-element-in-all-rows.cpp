//Link: https://leetcode.com/problems/find-smallest-common-element-in-all-rows/ 
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        if(mat.size() == 1) return mat[0][0];
        map<int, int> m;
        for(auto n : mat[0]) {
            ++m[n];
        }
        for(int i = 1; i < mat.size(); ++i) {
            for(auto n : mat[i])
                ++m[n];
        }
        for(auto &it  : m) {
            if(it.second == mat.size())
                return it.first;
        }
        return -1;
    }
};