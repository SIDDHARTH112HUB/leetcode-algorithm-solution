//Link: https://leetcode.com/problems/car-fleet/ 
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if( position.size() == 0 ) return 0;
        vector<pair<int, double> > cars;
        for( int i = 0; i<position.size(); i++ ){
            cars.push_back({position[i], (target-position[i])*1.0/speed[i]});
        }
        sort( cars.begin(), cars.end() );
        int cnt = 0;
        double cur = 0;
        for( int i = cars.size()-1; i>=0; i--){
            if( cars[i].second >cur ){
                cnt++;
                cur = cars[i].second;
            }
        }
        return cnt;
    }
};

//0 5 10 3 8
//1 1 2  3 4
//0 2 4
//2 3 1 