//Link: https://leetcode.com/problems/loud-and-rich/ 
class Solution {
public:
    unordered_map<int, vector<int> > graph;
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for( auto &r:richer){
            graph[r[1]].push_back(r[0]);
        }
        vector<int> ans;
        vector<int> memo(quiet.size(), -1);
        for( int i = 0; i<quiet.size(); i++){
            dfs(i, quiet, memo);
        }
        return memo;
    }
    int dfs(int id, vector<int> &quiet, vector<int> &memo){
        if( memo[id] >= 0 ){
            return memo[id];
        }
        memo[id] = id;
        for( int r: graph[id]){
            if( quiet[memo[id]] > quiet[ dfs(r, quiet, memo) ]){
                memo[id] = memo[r];
            }
        }
        return memo[id];
    }
};