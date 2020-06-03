//Link: https://leetcode.com/problems/find-anagram-mappings/ 
class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int, int> bmap;
        int idx = 0;
        for( int b : B){
            bmap[b] = idx;
            idx++;
        }
        idx = 0;
        vector<int> ans;
        for(int a : A){
            ans.push_back(bmap[A[idx]]);
            idx++;
        }
        return ans;
    }
};