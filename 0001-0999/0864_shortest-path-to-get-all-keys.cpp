//Link: https://leetcode.com/problems/shortest-path-to-get-all-keys/ 
class Solution {
public:
    
    int getKeyBlockInt(char c){
        if( c >= 'a') c = 'A'+ (c-'a');
        return (1 << ( c-'A'));
    }
    int hash(int x, int y, int key){
        return (x<<16) | (y<<8) | key;
    }
    int shortestPathAllKeys(vector<string>& grid) {
        int all_keys=0, steps = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<int> q;
        //unordered_set<int> visited;
        vector<vector<vector<int> > > visited(n, vector<vector<int> >(m, vector<int>(64)));
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m ; j++){
                char c = grid[i][j];
                if( c == '@'){
                    q.push( (i<<16) | (j << 8)  );
                    //visited.insert((i<<16) | (j << 8));
                    visited[i][j][0] = 1;
                }else if( c >= 'a' && c <= 'f'){
                    all_keys = all_keys | this->getKeyBlockInt(c);
                }
            }
        }
        int dist[5] = {-1,0,1,0,-1};
        
        while( q.size() > 0 ){
            int size = q.size();
            while( size-- > 0 ){
                int s = q.front();
                q.pop();
                int x = s >> 16, y = (s >> 8) & 0xFF, key = s & 0xFF;
                if( key == all_keys ) return steps;
                for( int i = 0; i<4; i++){
                    int nx = dist[i] + x;
                    int ny = dist[i+1] + y;
                    if( nx >= n || nx < 0 || ny >= m || ny < 0 ) continue;
                    char nc = grid[nx][ny];
                    if( nc == '#')continue;
                    if( nc >= 'A' && nc <= 'F' && ( (key & this->getKeyBlockInt(nc)) == 0 ) ) continue;
                    int new_key = key;
                    if( nc >= 'a' && nc <= 'f')
                        new_key |= this->getKeyBlockInt(nc);
                    int new_state = hash(nx, ny, new_key);
                    if( visited[nx][ny][new_key] )continue;
                    q.push( new_state );
                    //visited.insert(new_state);
                    visited[nx][ny][new_key] = 1;
                }
            }
            steps++;
        }
        return -1;
    }
};