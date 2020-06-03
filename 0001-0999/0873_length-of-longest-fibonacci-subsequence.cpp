//Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/ 
class Solution {
public:
    /*int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        unordered_set<int> dict(A.begin(), A.end());
        int ans = 0;
        for( int i = 0; i<n; i++){
            int cnt = 0;
            
            for( int j = i+1; j<n; j++){
                int n2 = A[i];
                int n1 = A[j];
                int cnt = 0;
                while( dict.count(n1+n2) ){
                    cnt = cnt==0?3:cnt+1;
                    int cur = n1+n2;
                    n2 = n1;
                    n1 = cur;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }*/
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_map<int, int> dict;
        
        int n  = A.size();
        vector< vector<int> > dp(n, vector<int>(n,2));
        for( int i = 0; i<n; i++){
            dict[A[i]] = i;
        }
        int max_cnt = 0;
        int ans = 0;
        for( int i = 0; i<n; i++){
            int n1 = A[i];
            for( int j = i+1; j<n; j++){
                int n2 = A[j];
                int prev = n2-n1;
                if( dict.find(n2-n1) != dict.end() && dict[prev] < i ){
                    dp[i][j] = dp[dict[prev]][i] + 1;
                    
                }
                ans = max(dp[i][j], ans);
            }
        }
        return ans>2?ans:0;
    }
    
};