//Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/ 
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int> > m;
        vector<vector<int> > ans;
        for(int i = 0; i < groupSizes.size(); ++i) {
            int s = groupSizes[i];
            m[s].push_back(i);
            if(m[s].size() == s) {
                ans.push_back(m[s]);
                m[s] = {};
            }
        }
        return ans;
    }
};