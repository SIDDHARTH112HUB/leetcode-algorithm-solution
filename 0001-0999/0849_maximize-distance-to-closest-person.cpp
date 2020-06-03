//Link: https://leetcode.com/problems/maximize-distance-to-closest-person/ 
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = -1, r=-1;
        int ans = 0;
        for( int i = 0; i<seats.size(); i++){
            if( seats[i] == 0){
                l = min(i, l);
                r = max(i, r);
            }
            else{
                if( l == -1 )
                    ans = i;
                else{
                    ans = max((r-l+1)/2, ans);
                }
                l = i;
                r = i;
            }
        }
        if( seats[seats.size()-1]==0 ){
            ans = max(r-l, ans);
        }
        return ans;
    }
};