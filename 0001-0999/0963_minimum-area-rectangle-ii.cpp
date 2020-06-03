//Link: https://leetcode.com/problems/minimum-area-rectangle-ii/ 
class Solution {
public:
    double dist(int x1, int y1, int x2, int y2){
        return sqrt((x1 - x2 )* (x1-x2) + (y1-y2) * (y1-y2) );
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<long long, vector<vector<int> > > m;
        int size = points.size();
        for( int i = 0; i < size; i++ ){
            for( int j = i+1; j< size; j++){
                auto &p1 = points[i];
                auto &p2 = points[j];
                long long key = ((long long)(p1[0] + p2[0]) << 16) + (p1[1] + p2[1]);
                m[key].push_back({p1[0], p1[1], p2[0], p2[1]});
            }
        }
        double ans = 0;
        for( auto &it : m){
            for( int i = 0; i < it.second.size(); i++ ){
                for( int j = i+1; j < it.second.size(); j++){
                    auto &p1 = it.second[i];
                    auto &p2 = it.second[j];
                    if( (p1[0] -p2[0] ) * (p1[0] - p2[2]) + (p1[1] - p2[1] )*( p1[1] -p2[3]) == 0  ){
                        double area = dist(p1[0],p1[1], p2[0],p2[1]) * dist(p1[0],p1[1], p2[2], p2[3]);
                        if( ans == 0 || ans > area ) 
                            ans = area;
                    }
                }
            }
        }
        return ans;
    }
};