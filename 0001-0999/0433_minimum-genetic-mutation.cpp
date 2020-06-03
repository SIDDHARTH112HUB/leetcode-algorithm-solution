//Link: https://leetcode.com/problems/minimum-genetic-mutation/ 
class Solution {
public:
    int diff_count( string &a, string &b){
        int cnt = 0;
        for( int i = 0; i<a.size(); i++){
            if( a[i] != b[i])
                cnt++;
        }
        return cnt;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if( bank.size() == 0 ) return -1;
        bank.push_back(start);
        int n = bank.size();
        vector<vector<int> > dist(n, vector<int>(n, 0));

        for( int i = 0; i < bank.size(); i++){
            for( int j = i+1; j<bank.size(); j++){
                dist[i][j] = diff_count(bank[i], bank[j]);
            }
        }
        unordered_set<int> visited;
        queue<int> q;
        q.push( n - 1);
        int ans = 0;
        while( q.size() ){
            int len = q.size();
            ++ans;
            for( int i = 0; i<len; i++){
                int t = q.front();q.pop();
                visited.insert(t);
                for( int j = 0; j<n; j++ ){
                    if( ( dist[j][t] != 1 && dist[t][j]!=1 )  || visited.count(j) != 0 ) continue;
                    if( bank[j] == end ) return ans;
                    q.push(j);
                }
            }
        }
        return -1;
        
    }
};