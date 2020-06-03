//Link: https://leetcode.com/problems/squares-of-a-sorted-array/ 
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        for( int a : A){
            ans.push_back(a*a);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};