//Link: https://leetcode.com/problems/count-of-range-sum/ 
class Solution {
public:
    
     int countRangeSum(vector<int> &nums, int lower, int upper) {
        // write your code here
        map<long long, long long > m;
        m[0] = 1;
        long long sum = 0;
        int ans = 0;
        for( int i = 0; i< nums.size(); i++){
            long long n = nums[i];
            sum += n;
            
            auto b = m.lower_bound(sum-upper);
            auto e = m.upper_bound(sum-lower);
            while( b != e && b != m.end() ){
                ans += b->second;
                ++b;
            }
            ++m[sum];
            
        }
        return ans;
    }
};