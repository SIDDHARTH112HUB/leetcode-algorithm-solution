//Link: https://leetcode.com/problems/leftmost-column-with-at-least-a-one/ 
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto point = binaryMatrix.dimensions();
        int rows = point[0], cols = point[1];
        int ans = INT_MAX;
        while(rows-- > 0) {
            int l = 0, r = cols - 1;
            while(l <= r) {
                int mid = (l + r) / 2;
                int val = binaryMatrix.get(rows, mid);
                if(val == 1) {
                    ans = min(ans, mid);
                    r = mid - 1;
                    
                }
                else
                    l = mid + 1;
            }
            
        }
        return ans == INT_MAX ? -1 : ans;
    }
};