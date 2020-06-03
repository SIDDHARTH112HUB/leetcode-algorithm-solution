//Link: https://leetcode.com/problems/card-flipping-game/ 
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        map<int, int> same;
        for( int i = 0; i<fronts.size(); i++){
            if( fronts[i] == backs[i])
                same[fronts[i]] = 1;
        }
        
        int ans = 3000;
        for( int i = 0; i<fronts.size(); i++){
            if( fronts[i] != backs[i]){
                if( same[fronts[i]] == 0 )
                    ans = min(fronts[i], ans);
                if( same[backs[i]] == 0 )
                    ans = min(backs[i], ans);
            }
            
                
        }
        if( ans == 3000 )
            return 0;
        return ans;
     }
};