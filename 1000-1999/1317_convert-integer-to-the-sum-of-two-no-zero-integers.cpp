//Link: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/ 
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; ++i) {
            int a = i, b = n - i;
            auto s = to_string(a) + to_string(b);
            bool f = true;
            for(auto c : s) {
                if(c == '0'){
                    f = false;
                    break;
                }
            }
            if(f) return {i, n - i};
            
        }
        return {};
    }
};