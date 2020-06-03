//Link: https://leetcode.com/problems/koko-eating-bananas/ 
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while( l < r ){
            int m = (l + r ) /2;
            int total = 0;
            for( auto pile : piles)
                total += pile / m + (pile %m > 0 ? 1 : 0);
            if( total > H )
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};