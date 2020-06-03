//Link: https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/ 
class Solution {
public:
    map<int, vector<int> > m;
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sums;
        int len = nums.size() - k + 1;
        int sum = 0;
        for( int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if( i >= k - 1){
                sum -= i<k?0:nums[i-k];
                sums.push_back(sum);
                //cout<<sum<<" ";
            }
        }
        //cout<<endl;
        int left[len] = {0};
        int best = 0;
        for( int i = 0; i< len ; i++){
            if( sums[i] > sums[best] ){
                best = i;
            }
            left[i] = best;
        }
        int right[len]= {0};
        best = len-1;
        for( int i = len-1; i>=0; i--){
            if( sums[i] > sums[best])
                best = i;
            right[i] = best;
        }
        vector<int> res = {0, k, 2*k};
        for( int i = k; i< len-k; i++){
            if( sums[left[i-k]] + sums[i]+sums[right[i+k]] >  sums[res[0]] + sums[res[1]]+sums[res[2]] ){
                res[0] = left[i-k];
                res[1] = i;
                res[2] = right[i+k];
            }
        }
        return res;
    }
};