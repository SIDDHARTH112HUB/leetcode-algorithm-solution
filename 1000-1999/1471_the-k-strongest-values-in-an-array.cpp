//Link: https://leetcode.com/problems/the-k-strongest-values-in-an-array/ 
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int median = arr[(arr.size() - 1)/2];
        int i = 0, j = arr.size() - 1;
        while(k--) {
            if(abs(arr[j] - median) >= abs(arr[i] - median))
                --j;
            else
                ++i;
        }
        arr.erase(arr.begin() + i, arr.begin() + j + 1);
        return arr;
    }
};