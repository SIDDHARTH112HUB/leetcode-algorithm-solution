//Link: https://leetcode.com/problems/minimum-cost-to-hire-k-workers/ 
class Solution {
public:
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int> > qw;
        for(int i = 0; i < wage.size(); ++i) {
            qw.push_back({wage[i]*1.0/quality[i],quality[i]} );
        }
        sort(qw.begin(), qw.end());
        priority_queue<int> pq;
        int qsum = 0;
        double res = DBL_MAX;
        for(int i = 0; i < qw.size(); ++i) {
            qsum += qw[i].second;
            pq.push(qw[i].second);
            if(pq.size() > K) {
                qsum -= pq.top();
                pq.pop();
            }
            if(pq.size() == K) {
                res = min(res, qsum * qw[i].first);
            }
        } 
        return res;
    }
    
};