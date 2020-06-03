//Link: https://leetcode.com/problems/minimum-number-of-refueling-stops/ 
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue< int, vector<int>, less<int> > pq;
        int distance = startFuel;
        startFuel = 0;
        int ans = 0, i = 0;
        while( target > distance ){
            while( i < stations.size() && distance >= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if( pq.size()  == 0 && (i == stations.size() || distance < stations[i][0]) )
                return -1;
            if(  pq.size() ){
                distance += pq.top();
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};