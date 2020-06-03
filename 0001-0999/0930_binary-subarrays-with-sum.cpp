//Link: https://leetcode.com/problems/binary-subarrays-with-sum/ 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int m[A.size()+1] = {0};
        m[0] = 1;
        int psum = 0;
        int res = 0;
        for( auto n : A ){
            psum += n;
            if( psum >= S )
                res += m[psum - S ];
            m[psum]++;
        }
        return res;
    }
};