//Link: https://leetcode.com/problems/all-paths-from-source-to-target/ 
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int des = graph.size()-1;
        vector< vector<int> > path,ans;
        for(auto n: graph[0] ){
            vector<int> p;
            p.push_back(0);
            p.push_back(n);
            if( n == des )
                ans.push_back(p);
            else
                path.push_back(p);
        }
        while(path.size()>0){
            auto back = path.back();
            path.pop_back();
            for( auto n: graph[back.back()]) {
                printf("back.back():%d , n:%d\n",back.back(), n );
                back.push_back(n);
                if(n == des){
                    ans.push_back(back);
                }else{
                    path.push_back(back);
                }
                back.pop_back();
            }
        }
        return ans;
    }
};