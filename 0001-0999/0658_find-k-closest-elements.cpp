//Link: https://leetcode.com/problems/find-k-closest-elements/ 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int i = 0, j = arr.size() - 1;
        while(j - i >= k) {
            if(abs(arr[j] - x) >= abs(arr[i] - x))
                --j;
            else
                ++i;
        }
        return vector<int>(arr.begin()+i, arr.begin() + j + 1);
    }
};