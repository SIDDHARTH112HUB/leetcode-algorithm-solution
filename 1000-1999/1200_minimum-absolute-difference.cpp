//Link: https://leetcode.com/problems/minimum-absolute-difference/ 
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        map<int, vector<vector<int> > > m;
        for(int i = 1; i < arr.size(); ++i) {
            
            m[abs(arr[i] - arr[i-1])].push_back({arr[i-1], arr[i]});
            
        }
        return m.begin()->second;
    }
};