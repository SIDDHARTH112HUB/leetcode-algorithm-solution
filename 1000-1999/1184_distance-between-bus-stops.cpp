//Link: https://leetcode.com/problems/distance-between-bus-stops/ 
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(start == destination) return 0;
        int sum = accumulate(distance.begin(), distance.end(), 0);
        int a = 0;
        for(int i = min(start, destination); i < max(start, destination); ++i) {
            a += distance[i];
        }
        return min(a, sum - a);
    }
};