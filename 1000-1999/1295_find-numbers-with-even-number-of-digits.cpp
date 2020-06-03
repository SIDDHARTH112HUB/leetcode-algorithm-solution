//Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/ 
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int n : nums) {
            int c = 0;
            while(n > 0) {
                ++c;
                n /= 10;
            }
            ans += (c %2 ==0);
        }
        return ans;
    }
    
};