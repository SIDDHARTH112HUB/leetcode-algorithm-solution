//Link: https://leetcode.com/problems/ipo/ 
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int ans = 0;
        priority_queue<pair<int, int> > pq, pq2;
        for(int i = 0; i < Profits.size(); ++i) {
            if(Capital[i] > W) {
                pq2.push({-Capital[i], Profits[i]});
            }else{
                pq.push({Profits[i], Capital[i]});
            }
        }
        
        while(k-- >0 && pq.size()) {
            W += pq.top().first;
            pq.pop();
            while(pq2.size() && -pq2.top().first <= W) {
                pq.push({pq2.top().second, -pq2.top().first});
                pq2.pop();
            }
        }
        return W;
    }
};