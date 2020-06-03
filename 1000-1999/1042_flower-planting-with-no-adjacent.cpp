//Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/ 
class Solution {
public:
    unordered_map<int, unordered_set<int> > graph;
    vector<int> ans;
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        ans.resize(N);
        for(auto &path: paths) {
            int x = path[0];
            int y = path[1];
            graph[x].insert(y);
            graph[y].insert(x);
        }
        for(int i = 1; i <= N; i++)
            dfs(i);
        return ans;
    }
    
    void dfs(int garden) {
        if(ans[garden-1] > 0)
            return;
        
        for( int f = 1; f <=4; f++) {
            bool isFind = true;
            for(int g : graph[garden]) {
                if ( ans[g-1] == f) {
                    isFind = false;
                    break;
                }
            }
            if(isFind){
                ans[garden-1] = f;
                break;
            }
        }
        for(auto g : graph[garden]) {
            dfs(g);
        }
    }
};