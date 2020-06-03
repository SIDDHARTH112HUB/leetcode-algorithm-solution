//Link: https://leetcode.com/problems/consecutive-numbers-sum/ 
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        
        int ans = 0;
        for(int i = 1; i <= N; ++i) {
            int n = N - i * (i + 1 ) /2;
            if(n < 0) break;
            if(n % i == 0)
                ++ans;
        }
        return ans;
    }
};