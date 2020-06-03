//Link: https://leetcode.com/problems/rectangle-overlap/ 
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int blx1 = rec1[0], bly1=rec1[1], trx1=rec1[2], try1=rec1[3];
        int blx2 = rec2[0], bly2=rec2[1], trx2=rec2[2], try2=rec2[3];
        return max(blx1, blx2) < min(trx1, trx2 ) && max(bly1, bly2) < min(try1, try2 );
    }
};