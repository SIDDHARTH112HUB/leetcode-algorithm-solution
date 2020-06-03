//Link: https://leetcode.com/problems/reach-a-number/ 
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int s = 0;
        int ans = 0;
        while( s < target ){
            s += (++ans);
            if( s == target )
                return ans;
        }
        if( s == target ) return ans;
        while( (s-target) % 2 ){
            s += (++ans);
        }
        return ans;
    }
};