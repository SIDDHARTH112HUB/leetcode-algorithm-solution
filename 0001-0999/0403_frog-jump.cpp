//Link: https://leetcode.com/problems/frog-jump/ 
class Solution {
public:
    map<int, set<int> > dp;
    int last_step;
    bool canCross(vector<int>& stones) {
        if( stones.size() <= 1 ){
            if( stones[0] != 0 ) return false;
            if( stones[1] != 1 ) return false;
            return true;
        }
        
        int num = 0;
        for( auto n: stones ){
            dp[n] = set<int>();
        }
        dp[1].insert(1);
        for( int i = 1; i<stones.size(); i++){
            num = stones[i];
            for(auto n:dp[num]){
                if( dp.find(n+1+num) != dp.end() ){
                    dp[n+1+num].insert(n+1);
                }
                if(n-1>0 && dp.find(num+n-1) != dp.end()){
                    dp[num+n-1].insert(n-1);
                }
                if(n>0 && dp.find(num+n) != dp.end()){
                    dp[num+n].insert(n);
                }
            }
        }
        return dp[num].size()>0;
    }
    
    bool canCross(vector<int>& stones) {
        
    }
    
    void dfs( vector<int> &stones, int idx, int step){
    }
};