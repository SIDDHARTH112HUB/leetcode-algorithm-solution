//Link: https://leetcode.com/problems/max-increase-to-keep-city-skyline/ 

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row_size = grid.size();
        int col_size = grid[0].size();
        int row_max[row_size] = {0};
        int col_max[col_size] = {0};
        int idx = 0;
        for(auto &g:grid){
            row_max[idx++] = *max_element(g.begin(), g.end());
            int cidx = 0;
            for(auto n:g){
                if(col_max[cidx] < n){
                    col_max[cidx] = n;
                }
                cidx++;
            }
        }
        cout<<endl;
        idx = 0;
        int sum = 0;
        for(auto &g:grid){
            int cidx = 0;
            for( int &n: g){
                int n1 = row_max[idx] < col_max[cidx]?row_max[idx]:col_max[cidx];
                sum += abs(n1 - n);
                cidx++;
                //cout<<n<<" ";
            }
            //cout<<endl;
            idx++;
        }
        return sum;
        
        
    }
};