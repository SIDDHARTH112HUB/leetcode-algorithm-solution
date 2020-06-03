//Link: https://leetcode.com/problems/score-after-flipping-matrix/ 
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        vector<int> ans;
        int m = A.size();
        int n = A[0].size();
        for( int i = 0; i<m; i++){   // 1. flip by row
            int num1 = 0;
            int num2 = 0;
            for( int j = 0; j<n;j++){
                num1 |= A[i][j]<<(n-j-1);
                num2 |= (!A[i][j])<<(n-j-1);
            }
            if( num2 > num1 )
                num1 = num2;
            ans.push_back(num1);
        }
        for( int j = 0; j <n;j++){  // 2. flip by column
            int one = 0, zero=0;
            for( int i = 0; i<m;i++){
                int num = ans[i] & (0x01 <<j);
                if( num == 0 )
                    zero++;
                else
                    one++;
            }
            if( zero>one){
                for( int i = 0; i<m;i++){
                    int num = ans[i] & (0x01 <<j);
                    if( num == 0 ){
                        ans[i] |= 0x01 <<j;
                    }else{
                        ans[i] &= ((0x01<<j)^(0xFFFFFFFF));
                    }
                }
            }
        }
        int total = 0;
        for( int i = 0; i<ans.size(); i++)
            total += ans[i];
        return total;
    }
};