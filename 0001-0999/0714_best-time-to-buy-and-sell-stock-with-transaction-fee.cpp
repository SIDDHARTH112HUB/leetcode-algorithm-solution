//Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/ 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if( n <= 1 ) return 0;
        int  buy[n]={0}, sell[n] = {0};
        for( int i = 0; i< n ; i++){
            int p = prices[i];
            buy[i] = max( (i>0?sell[i-1]:0) - p - fee, (i>0? buy[i-1]: INT_MIN) );
            sell[i]= max( (i>0?buy[i-1]:INT_MIN) + p , (i>0? sell[i-1]:0)  );
        }
        return sell[n-1];
    }
};