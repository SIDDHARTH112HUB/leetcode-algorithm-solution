//Link: https://leetcode.com/problems/gray-code/ 
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int pow = 1;
        for( int i = 1; i<=n; i++ ){
            int N = ans.size();
            if( i > 1 )pow*=2;
            for( int j = N-1; j>=0; j-- ){
                ans.push_back(ans[j] + pow);
            }
        }
        return ans;
    }
};