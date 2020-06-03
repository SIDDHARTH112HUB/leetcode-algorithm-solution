//Link: https://leetcode.com/problems/diet-plan-performance/ 
class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
        int sum = 0, ans = 0;
        for(int i = 0; i < calories.size(); ++i) {
            sum += calories[i];
            if(i >= k-1) {
                sum -= i >= k ? calories[i-k] : 0;
                if(sum > upper) ans += 1;
                else if(sum < lower) ans -= 1;
            }
        }
        return ans;
    }
};