//Link: https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/ 
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        if(mx < 0) return mx;
        int a = 0, b = 0;
        for(int i = 0; i < arr.size(); ++i) {
            int preva = a, prevb = b;
            a = max(preva + arr[i], arr[i]);
            b = max(max(0, prevb + arr[i]), preva);
            mx = max(max(a, b), mx);
        }
        
        return mx;
    }
};