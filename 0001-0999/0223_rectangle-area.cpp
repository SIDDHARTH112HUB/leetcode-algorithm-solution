//Link: https://leetcode.com/problems/rectangle-area/ 
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E);
        int right = max( min(C,G), left);
        int bottom = max(B, F);
        int top = max(min(D, H), bottom);
        return abs((A-C)*(B-D)) - abs((left-right)*(bottom-top)) + abs((E-G)*(F-H));
    }
};