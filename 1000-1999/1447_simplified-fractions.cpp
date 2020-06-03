//Link: https://leetcode.com/problems/simplified-fractions/ 
class Solution {
public:
    int gcd(int a, int b) {
        if( a % b ==0) return b;
        return gcd(b, a % b);
    }
    vector<string> simplifiedFractions(int n) {
        if(n == 1) return {};
        set<string> ans;
        for(int i = 1; i < n; ++i) {
            for(int j = i + 1; j <= n; ++j) {
                int g = gcd(j, i);
                ans.insert(to_string(i / g) + "/" + to_string(j/g));
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};