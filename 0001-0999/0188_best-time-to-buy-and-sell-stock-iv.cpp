//Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/ 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if( k <= 0 ) return 0;
        int n = prices.size();
        if( n <= 1) return 0;
        if( k > n/2) k = n/2+1;
        int b[k], s[k] = {0};
        
        
        
        for( int i = 0; i< k; i++)
            b[i] = INT_MIN;
        for( int i = 0; i<n; i++){
            int p = prices[i];
            //b[0] = max(b[0], 0 - p);
            //s[0] = max(b[0] + p, s[0]);
            for( int j = 0; j<k; j++){
                b[j] = max( b[j], ( j> 0?s[j-1]:0) - p);
                s[j] = max( b[j] + p, s[j]);
            }
        }
        return s[k-1];
    }
};