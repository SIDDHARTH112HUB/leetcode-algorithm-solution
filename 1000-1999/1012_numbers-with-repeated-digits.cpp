//Link: https://leetcode.com/problems/numbers-with-repeated-digits/ 
class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int src = N;
        ++N;
        vector<int> nums;
        while(N > 0){
            nums.push_back(N%10);
            N /= 10;
        }
        reverse(nums.begin(), nums.end());
        int res = 0;
        for(int i = 1; i < nums.size(); i++){
            res += 9 * helper(9, i - 1);
        }
        set<int> seen;
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = i > 0 ? 0 : 1; j < nums[i]; ++j){
                if(!seen.count(j))
                    res += helper(9 - i, nums.size() - i - 1);
            }
            int n = nums[i];
            if(seen.count(n)) break;
            seen.insert(n);
        }
        return src - res;
    }
    
    int helper(int m, int n) {
        return n == 0 ? 1 : helper(m, n-1) * (m - n + 1);
    }
};