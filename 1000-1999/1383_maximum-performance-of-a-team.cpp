//Link: https://leetcode.com/problems/maximum-performance-of-a-team/ 
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<long long, long long> > arr;
        long long ans = 0, sumS = 0;
        for(int i = 0; i < speed.size(); ++i) {
            ans = max(ans, (long long)speed[i] * (long long)eff[i]);
            arr.push_back({eff[i], speed[i]});
        }
        //cout<<"begin"<<endl;
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        
        priority_queue<long long, vector<long long >, greater<long long > > pq;
        for(int i = 0; i < arr.size(); ++i) {
            long long sig = arr[i].second * arr[i].first;
            sumS += arr[i].second;
            pq.push(arr[i].second);
            if(pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            ans = max(ans, sumS * arr[i].first);
        }
        ans = ans % (1000000007);
        return ans;
    }
};