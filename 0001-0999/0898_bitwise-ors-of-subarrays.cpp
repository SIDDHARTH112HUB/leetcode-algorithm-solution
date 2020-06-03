//Link: https://leetcode.com/problems/bitwise-ors-of-subarrays/ 
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> s1, s2,res;
        for( int i : A){
            s1 = {i};
            for( int j:s2)
                s1.insert(i|j);
            
            s2 = s1;
            for( int j:s1) res.insert(j);
        }
        return res.size();
    }
};