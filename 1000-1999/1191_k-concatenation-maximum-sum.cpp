//Link: https://leetcode.com/problems/k-concatenation-maximum-sum/ 
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long mx = *max_element(arr.begin(), arr.end());
        if(mx <= 0) return 0;
        long long sum = accumulate(arr.begin(), arr.end(), 0);
        long long ans = sum;
        int size = arr.size();
        for(int i = 0; i < size*2; ++i) {
            arr.push_back(arr[i%size]);
        }
        if(k > 1) size *= 2;
        long long res = 0;
        sum = 0;
        mx = 0;
        for(int i = 0; i < arr.size(); ++i) {
            sum = max((long long)arr[i] + sum, (long long)arr[i]);
            res = max(res, sum);
        }
        long long mn1 = 0, mn2 = 0;
        sum = 0;
        long long sum2 = 0;
        int l = 0;
        for(int i = 0; i < size; ++i) {
            sum += arr[i];
            if(sum < mn1){
                mn1 = sum;
                l = i + 1;
            }
        }
        for(int i = size - 1; i > l; --i) {
            sum2 += arr[i];
            if(sum2 < mn2){
                mn2 = sum2;
            }
        }
        return max(max(ans, res),  ans * k - (mn1 < 0 ? mn1 : 0) - (mn2 < 0 ?mn2 :0)) % 1000000007;
    }
};