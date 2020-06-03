//Link: https://leetcode.com/problems/four-divisors/ 
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int n : nums) {
            int sq = sqrt(n);
            int sum = 0;
            int cnt = 0;
            for(int i = 1; i <= sq; ++i) {
                if(n % i == 0) {
                    sum = sum + i;
                    ++cnt;
                    if(n /i != i){
                        sum += n / i;
                        ++cnt;
                    }
                }
            }
            if(cnt == 4)
                ans += sum;
        }
        return ans;
    }
};