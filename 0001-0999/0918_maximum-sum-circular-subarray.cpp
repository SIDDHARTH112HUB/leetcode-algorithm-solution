//Link: https://leetcode.com/problems/maximum-sum-circular-subarray/ 
class Solution {
public:
    int maxSum(vector<int>& A ){
        int max_sum = -1000000, cur_max=-1000000,max_end = 0;
        for(int &a:A){
            max_sum = max(max_sum+a,a );
            cur_max = max(cur_max, max_sum);
        }
        return cur_max;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int max_sum = maxSum(A);
        if( max_sum < 0 ) return max_sum;
        int sum = 0;
        for( int &n : A ){
            sum += n;
            n = -n;
        }
        int max_sum2 = sum + maxSum(A);
        return max_sum > max_sum2 ? max_sum : max_sum2;
    }
};