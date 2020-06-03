//Link: https://leetcode.com/problems/find-lucky-integer-in-an-array/ 
class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> m;
        for(int n : arr)
            ++m[n];
        for(auto it = m.rbegin(); it != m.rend(); ++it)
            if(it->first == it->second)
                return it->first;
        return -1;
    }
};