//Link: https://leetcode.com/problems/pyramid-transition-matrix/ 
class Solution {
public:
    map<string, set<char> > dict;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        if( bottom.size() <= 1 )
            return true;
        if( dict.size() == 0 ){
            for( auto &str : allowed){
                dict[str.substr(0,2)].insert(str[2]);
            }
        }
        return dfs(bottom, "");
    }
    
    bool dfs(string bottom, string above ){
        if( above.size() == 1 && bottom.size() == 2 ) return true;
        if( above.size() + 1 == bottom.size() ) return dfs(above, "");
        int idx = above.size();
        string s = {bottom[idx], bottom[idx+1]};
        for( auto c : dict[s]){
            bool res = dfs( bottom, above+c);
            if( res )
                return res;
        }
        return false;
    }
};