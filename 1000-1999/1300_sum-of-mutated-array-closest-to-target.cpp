//Link: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/ 
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> prefix = arr;
        for(int i = 1; i < arr.size(); ++i) {
            prefix[i] += prefix[i-1];
        }
        int mx = INT_MAX;
        int ans;
        int cur;
        int l = 0, r = arr.back();
        int mid;
        while(l <= r) {
            mid = (l +r) /2;
            int idx = lower_bound(arr.begin(), arr.end(), mid) - arr.begin();
            int sum = mid * (prefix.size() - idx) + (idx > 0 ? prefix[idx - 1] : 0);
            //cout<<arr[idx]<<" sum:"<<sum<<" abs:"<<abs(sum - target)<<endl;
            int aa = abs(sum - target);
            if(aa <= mx) {
                if(aa == mx) {
                    if(sum < target){
                        cur = mid;
                    }
                }else {
                    mx = aa;
                    cur = mid;
                }
            }
            if(sum >= target) {
                r = mid - 1;
            }else
                l = mid + 1;
                
        }
        //cout<<mid<<" "<<cur<<endl;
        return cur;
    }
};