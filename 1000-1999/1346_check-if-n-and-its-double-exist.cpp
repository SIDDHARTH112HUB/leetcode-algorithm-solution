//Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/ 
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> m;
        for(auto n :arr) {
            if(m[n *2]) return true;
            if(m[n/2] && (n % 2 == 0)) return true;
            ++m[n];
        }
        return false;
    }
};