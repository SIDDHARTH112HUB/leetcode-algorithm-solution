//Link: https://leetcode.com/problems/grid-illumination/ 
class Solution {
public:
    unordered_map<int, int> row, col, dia, anti_dia;
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        set< pair<int, int> > l; //location
        for( auto &lamp: lamps){
            int x = lamp[0], y = lamp[1];
            l.insert({x, y});
            
            setLamp(x, y, 1);
        }
        int dx[9] = {0,0,0,1,-1, 1,1,-1,-1};
        int dy[9] = {0,1,-1,0,0, 1,-1,1,-1};
        vector<int> ans;
        for( auto &q : queries){
            int x = q[0], y = q[1];
            if( row[x] > 0 || col[y] > 0 || dia[x+y]>0 || anti_dia[x-y]>0 )
                ans.push_back(1);
            else
                ans.push_back(0);
            
            //remove lamp
            for( int i = 0; i<9; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if( l.count({nx, ny}) ){
                    setLamp(nx, ny, -1);
                }
            }
        }
        return ans;
    }
    
    void setLamp(int x, int y, int count){
        row[x] += count;
        col[y] += count;
        dia[x + y] += count;
        anti_dia[x - y] += count;
    }
};