//Link: https://leetcode.com/problems/generate-random-point-in-a-circle/ 
class Solution {
public:
    double x;
    double y;
    double r;
    Solution(double radius, double x_center, double y_center) {
        x = x_center, y = y_center, r = radius;
    }
    
    vector<double> randPoint() {
        while(true){
            double x1 = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            double y1 = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            if(x1 * x1 + y1 * y1 <= r * r) return {x + x1, y + y1};
        }
        return {};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */