//Link: https://leetcode.com/problems/single-number-ii/ 
class Solution {
public:
    int singleNumber(int A[], int n) {
        int bitnum[32];
        int res=0;
        memset(bitnum, 0, sizeof(bitnum));
        for(int j = 0; j<32; j++)
        {
            for(int i = 0; i < n ; i++)
            {
                bitnum[j] += ((A[i]>>j) & 0x01);
            }
            res |= (bitnum[j]%3)<<j;
        }
        return res;
    }
};