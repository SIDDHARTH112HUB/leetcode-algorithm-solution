//Link: https://leetcode.com/problems/rabbits-in-forest/ 
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> rabbit;
        int ans = 0;
        for( auto a : answers){
            if( a == 0 )
                ans+=1;
            else
                rabbit[a] += 1;
        }
        for( auto &it : rabbit){
            ans += ( ceil(it.second*1.0/(it.first+1) ) * (it.first+1) );
            
        }
        return ans;
    }
};