//Link: https://leetcode.com/problems/index-pairs-of-a-string/ 
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ans;
        for(auto &str : words) {
            auto f = text.find(str);
            while(f != string::npos) {
                ans.push_back({(int)f, (int)f + (int)str.size() - 1});
                f = text.find(str, f + 1);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};