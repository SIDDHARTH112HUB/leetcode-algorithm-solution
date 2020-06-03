//Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //int prev_buy, buy = INT_MIN, sell = 0, prev_sell = 0;
        
        int n = prices.size();
        if ( n <= 1 ) return 0;
        int buy[n]={0}, sell[n]={0};
        for( int i = 0; i< prices.size(); i++){
            int p = prices[i];
            buy[i] = max((i>1?sell[i-2]:0)-p, (i>0 ? buy[i-1]:INT_MIN) );
            sell[i] = max( (i>0?buy[i-1]:INT_MIN) + p ,i>0?sell[i-1]:0 );
            /*
            prev_buy = buy;
            buy = max( prev_sell - p, prev_buy);
            prev_sell = sell;
            sell = max( prev_buy + p, sell );*/
        }
        return sell[n-1];
    }
};