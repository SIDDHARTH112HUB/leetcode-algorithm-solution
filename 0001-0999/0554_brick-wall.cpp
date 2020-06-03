//Link: https://leetcode.com/problems/brick-wall/ 
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int N = wall.size();
        if( N == 0 ) return 0;
        map<int, int> lenMap;
        int wall_width = accumulate(wall[0].begin(), wall[0].end(), 0);
        int ans = 0;
        for( auto &bricks:wall ){
            int sum = 0;
            for( auto len:bricks){
                if( len == 0 )
                    continue;
                sum+=len;
                if( sum >= wall_width)
                    break;
                lenMap[sum]+=1;
                
            }
        }
        for( auto &iter:lenMap){
            if( iter.second > ans ){
                ans = iter.second;
            }
        }
        return N - ans;
    }
};