//Link: https://leetcode.com/problems/construct-the-rectangle/ 
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = ceil(sqrt(area));
        while( L <= area) {
            if(area % L == 0) {
                return {L, area/ L};
            }
            ++L;
        }
        return {-1, -1};
    }
};