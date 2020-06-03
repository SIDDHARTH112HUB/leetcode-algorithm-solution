//Link: https://leetcode.com/problems/largest-unique-number/ 
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        if(A.size() == 1) return A[0];
        map<int, int> m;
        for(auto n: A)
            ++m[n];
        for(auto it=m.rbegin(); it!=m.rend(); ++it){
            if(it->second == 1)
                return it->first;
        }
        return -1;
    }
};