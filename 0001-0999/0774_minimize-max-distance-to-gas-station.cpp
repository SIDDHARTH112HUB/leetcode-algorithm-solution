//Link: https://leetcode.com/problems/minimize-max-distance-to-gas-station/ 
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double l = 0, r = stations.back();
        while(l + 0.000001 < r) {
            int cnt = 0;
            double mid = (l + r) / 2;
            double cur = INT_MIN;
            for(int i = 1; i < stations.size(); ++i) {
                double p = stations[i];
                if(stations[i] - stations[i-1] > mid) {
                    cnt += (stations[i] - stations[i-1]) / mid;
                }
            };
            if(cnt > K)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};