//Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = -1;
        int max_profit = 0;
        for( auto &p:prices){
            if( min_price < 0 )
                min_price = p;
            else if( min_price > p ){
                min_price = p;
            }
            else{
                if (max_profit < p-min_price)
                    max_profit = p-min_price;
            }
        }
        return max_profit;
    }
};