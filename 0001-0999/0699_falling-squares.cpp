//Link: https://leetcode.com/problems/falling-squares/ 
class Solution {
public:
    
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> ans;
        if( positions.size() == 0 ) return ans;
        ans.push_back(positions[0].second);
        if( positions.size() == 1 ) return ans;
        map<int, int> height;
        height[0] = positions[0].second;
        int max_h = height[0];
        for( int i =1; i<positions.size(); i++ ){
            auto &p = positions[i];
            bool flag = false;
            for( int j=0; j<i; j++ ){
                auto &pos = positions[j];
                int h = height[h];
                if( !( pos.first+pos.second <= p.first || pos.first >= p.first+p.second)){
                    if( height[j] + p.second > height[i] ){
                        height[i] = height[j] + p.second;
                        flag = true;
                        if( max_h < height[i])
                            max_h = height[i];
                    }
                }
            }
            if( !flag ){
                height[i] = p.second;
                if( max_h < p.second )
                    max_h = p.second;
            }
            ans.push_back(max_h);
        }
        return ans;
    }
};