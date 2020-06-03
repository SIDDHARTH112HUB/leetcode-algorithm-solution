//Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/ 
int dp[1002][1002];
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxlen = 0, maxindex = 0;
        int AN = A.size();
        int BN = B.size();
        for(int i = 0; i < AN; ++i)
        {
            for(int j = 0; j < BN; ++j)
            {
                if(A[i] == B[j]){  
                if(i > 0 && j > 0){  
                    dp[i][j] = dp[i-1][j-1] + 1;  
                }else{  
                    dp[i][j] = 1;  
                }  
                  
                if(dp[i][j] > maxlen){
                    maxlen = dp[i][j];  
                }  
                }else{  
                    dp[i][j] = 0;  
                }  
            }
        }
        return maxlen;
    }
};