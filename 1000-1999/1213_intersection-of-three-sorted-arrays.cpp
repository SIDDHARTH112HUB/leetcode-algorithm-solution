//Link: https://leetcode.com/problems/intersection-of-three-sorted-arrays/ 
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> m1, m2, m3;
        for(auto n : arr1)
            ++m1[n];
        for(auto n : arr2)
            ++m2[n];
        for(auto n : arr3)
            ++m3[n];
        vector<int> ans;
        for(auto it : m1) {
            if(m2[it.first] > 0 && m3[it.first] > 0)
                ans.push_back(it.first);
        }
        return ans;
    }
};