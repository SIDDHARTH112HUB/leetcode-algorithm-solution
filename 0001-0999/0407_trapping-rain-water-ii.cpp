//Link: https://leetcode.com/problems/trapping-rain-water-ii/ 
typedef pair<int, pair<int, int> > Triple;
struct comp{
    bool operator () (const Triple &a, const Triple &b)
    {
        return a.first>b.first;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        vector<vector<int>> &h = heightMap;
        int m = heightMap.size();
        if(m<=2 ) return 0;
        int n = heightMap[0].size();
        if(n<=2) return 0;
        vector<vector<int>> flag(m, vector<int>(n));
        priority_queue<Triple, vector<Triple>, greater<Triple> > pq;
        for( int i =0; i<m; i++){
            pq.push({h[i][0],{i,0}  });
            pq.push({h[i][n-1],{i,n-1}  });
            flag[i][0] = h[i][0];
            flag[i][n-1] = h[i][n-1];
        }
        cout<<endl;
        for( int i =1; i<n-1; i++){
            pq.push({h[0][i],{0,i}  });
            pq.push({h[m-1][i],{m-1,i}  });
            flag[0][i] = h[0][i];
            flag[m-1][i] = h[m-1][i];
        }
        cout<<endl;
        int res = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {-1,0,1,0};
        while( pq.size() ){
            auto p = pq.top();
            pq.pop();
            flag[p.second.first][p.second.second] = -1;
            for( int i = 0; i<4; i++){
                int curH = h[p.second.first][p.second.second];
                int nx = p.second.first+ dx[i];
                int ny = p.second.second+ dy[i];
                
                if( nx >= 0 && ny >=0 && nx<m && ny <n){
                    if( flag[nx][ny] == -1 ) 
                        continue;
                    if( curH > h[nx][ny] && flag[nx][ny]>=0){
                        res += (curH - h[nx][ny]);
                        h[nx][ny] = curH;
                    }
                    if( flag[nx][ny] == 0 ){
                        pq.push({h[nx][ny],{nx, ny}});
                        flag[nx][ny] = h[nx][ny];
                    }
                }
            }
        }
        return res;
    }
};