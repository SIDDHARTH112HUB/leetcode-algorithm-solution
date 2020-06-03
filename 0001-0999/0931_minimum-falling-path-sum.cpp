//Link: https://leetcode.com/problems/minimum-falling-path-sum/ 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<map<int, int> > vm(101);
        int ans = INT_MAX;
        for( int i = 0; i<A[0].size(); i++){
            vm[0][i] += A[0][i];
            ans = min(vm[0][i], ans);
        }
        
        for( int i = 1; i<A.size(); i++ ){
            auto &vec = A[i];
            ans = INT_MAX;
            for( int j = 0; j < vec.size(); j++){
                int n = vec[j];
                vm[i][j] = n + vm[i-1][j];
                if( j - 1 >= 0 )
                    vm[i][j] = min( vm[i-1][j-1]+n, vm[i][j]);
                if( j + 1 < vec.size() )
                    vm[i][j] = min( vm[i-1][j+1]+n, vm[i][j]);
                ans = min(ans, vm[i][j]);
            }
        }
        return ans;
    }
};