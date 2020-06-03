//Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/ 
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int, int> m;
        for(auto n : arr)
            ++m[n];
        for(auto it : m) {
            if(it.second > arr.size() / 4)
                return it.first;
        }
        return 0;
    }
};