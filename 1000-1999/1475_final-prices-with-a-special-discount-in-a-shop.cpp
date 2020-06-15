//Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/ 
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i = 0; i < prices.size(); ++i) {
            int p = 0;
            for(int j = i + 1; j < prices.size(); ++j) {
                if(prices[i] >= prices[j]) {
                    p = prices[j]; break;
                }
            }
            ans.push_back(prices[i] - p);
        }
        return ans;
    }
};