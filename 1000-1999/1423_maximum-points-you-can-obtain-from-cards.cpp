//Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/ 
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k == 1){
            return max(cardPoints[0], cardPoints.back());
        }
        for(int i = 1; i < cardPoints.size(); ++i){
            cardPoints[i] += cardPoints[i-1];
        }
        
        int n = cardPoints.size();
        cardPoints.insert(cardPoints.begin(), 0);
        int res = 0;
        
        for(int i = 0; i <= k; ++i) {
            res = max(res, cardPoints[i] + cardPoints[n]- cardPoints[n - k + i]);
        }
        //res = max(res, ans.back() - ans[ans.size() - k-1]);
        return res;
    }
};