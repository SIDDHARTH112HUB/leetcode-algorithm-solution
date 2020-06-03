//Link: https://leetcode.com/problems/largest-triangle-area/ 
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int size = points.size();
        double ans = 0;
        for( int i = 0; i<size; i++){
            for( int j = i+1; j<size; j++){
                for( int k = j+1; k<size; k++){
                    auto &A = points[i];
                    auto &B = points[j];
                    auto &C = points[k];
                    double area = fabs( ( A[0] * (B[1] - C[1]) + B[0] * (C[1] - A[1]) + C[0] * (A[1] - B[1]))/2.0 );
                    if( area > ans )
                        ans = area;
                }
            }
        }
        return ans;
    }
};