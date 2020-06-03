//Link: https://leetcode.com/problems/minimum-cost-to-connect-sticks/ 
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int s: sticks)
            pq.push(s);
        int ans = 0;
        while(pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        return ans;
    }
};
