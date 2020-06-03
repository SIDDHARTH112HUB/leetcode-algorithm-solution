//Link: https://leetcode.com/problems/hand-of-straights/ 
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if( hand.size()%W != 0 ) return false;
        map<int, int> memo;
        for(int i : hand){
            memo[i]++;
        }
        for( auto &it:memo){
            while( it.second ){
                it.second--;
                for( int i = 1; i<W; i++){
                    if( memo[i+it.first] )
                        memo[i+it.first]--;
                    else
                        return false;
                }
            }
        }
        return true;
        //sort(hand.begin(), hand.end());
        //dfs
    }
};