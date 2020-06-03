//Link: https://leetcode.com/problems/pascals-triangle-ii/ 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if( rowIndex <= 0 ) return {1};
        vector<int> ans(rowIndex+1);
        ans[0] = 1;
        for( int i = 1; i<=rowIndex; i++){
            for( int j = i; j>=1; j--){
                ans[j] = ans[j] + ans[j-1];
            }
        }
        return ans;
    }
};