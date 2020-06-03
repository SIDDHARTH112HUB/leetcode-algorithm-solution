//Link: https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/ 
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if(i >= k) {
                sum -= arr[i-k];
            }
            if(i < k - 1) continue;
            if(sum/k >= threshold)
                ++ans;
        }
        return ans;
    }
};