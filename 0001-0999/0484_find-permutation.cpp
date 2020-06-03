//Link: https://leetcode.com/problems/find-permutation/ 
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans;
        for(int i = 0; i <= s.size(); ++i ) {
            if(i ==s.size() || s[i] == 'I' ) {
                int size = ans.size();
                for(int j = i + 1; j > size; --j) {
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};