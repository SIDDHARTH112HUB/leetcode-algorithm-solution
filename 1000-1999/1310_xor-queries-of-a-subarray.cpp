//Link: https://leetcode.com/problems/xor-queries-of-a-subarray/ 
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i-1];
        }
        for(auto &q : queries) {
            int o = arr[q[1]];
            if(q[0] > 0) {
                o ^= arr[q[0] - 1];
            }
            ans.push_back(o);
        }
        return ans;
    }
};