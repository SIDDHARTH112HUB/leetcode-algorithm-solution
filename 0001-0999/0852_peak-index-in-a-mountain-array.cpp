//Link: https://leetcode.com/problems/peak-index-in-a-mountain-array/ 
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return max_element(A.begin(), A.end()) - A.begin();
    }
};