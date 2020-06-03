//Link: https://leetcode.com/problems/complement-of-base-10-integer/ 
class Solution {
public:
    int bitwiseComplement(int N) {
        int n = 1;
        while(n < N) n = (n << 1) + 1;
        return n - N;
    }
};