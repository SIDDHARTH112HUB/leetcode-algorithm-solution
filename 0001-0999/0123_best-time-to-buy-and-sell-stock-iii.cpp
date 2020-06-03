//Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1=INT_MIN,b2=INT_MIN,s1=0,s2=0;
        int buy[2] = {INT_MIN, INT_MIN}, sell[2] = {0};
        for( int i = 0; i<prices.size(); i++ ){ 
            int p = prices[i];
            for(int j = 0; j < 2; ++j ) {
                buy[j] = max(buy[j], (j > 0 ?sell[j-1]:0) - p);
                sell[j] = max(sell[j], buy[j] + p);
            }
            b1 = max(b1, 0 - p );
            s1 = max(s1, b1 + p);
            b2 = max(b2, s1 - p);
            s2 = max(s2, b2 + p);
        }
        return sell[1];
        return s2;
    }
};