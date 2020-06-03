//Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/ 
class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int N, int K) {
        if( N== 1) {
            //if( K == 0 )
                return {0,1,2,3,4,5,6,7,8,9};   
            //return {};
        }
        
        for( int i = 1; i<=9; i++ ){
            dfs(i, N-1, K);
        }
        return ans;
    }
    
    void dfs( int num, int N, int K){
        if( N == 0 ) {
            ans.push_back(num);
            return;
        }
        if( num % 10 + K <= 9 ){
            dfs(num*10 +num % 10 + K, N-1, K );
        }
        if( num % 10 - K >=0 && K > 0 ){
            dfs(num*10 +num % 10 - K, N-1, K );
        }
    }
};