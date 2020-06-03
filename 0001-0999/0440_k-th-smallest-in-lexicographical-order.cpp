//Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/ 
class Solution {
public:
    int findKthNumber(int n, int k) {
        long cur = 1;
        --k;
        while(k > 0) {
            long first = cur, last = cur + 1, step = 0;
            while(first <= n) {
                step += min((long)n + 1, last) - first;
                first *= 10;
                last *= 10;
            }
            if(step > k) {
                --k;
                cur *= 10;
            }else {
                k -= step;
                ++cur;
            }
        }
        return cur;
    }
};