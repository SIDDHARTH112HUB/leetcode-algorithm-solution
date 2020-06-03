//Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/ 
class Solution {
public:
    int numberOfSteps (int num) {
        int ans = 0;
        while(num > 0) {
            ++ans;
            if(num % 2)
                --num;
            else
                num/=2;
        }
        return ans;
    }
};