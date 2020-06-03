//Link: https://leetcode.com/problems/reaching-points/ 
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx <= tx && sy <= ty) {
            if(tx > ty) {
                tx %= ty;
            }else {
                ty %= tx;
            }
        }
        return tx > ty ? 
            (tx == sx && (ty == sy % sx)) : 
            (ty == sy && (tx == sx % sy));
    }
};