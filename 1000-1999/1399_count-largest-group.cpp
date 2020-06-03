//Link: https://leetcode.com/problems/count-largest-group/ 
class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int > m;
        int mx = 0;
        for(int i = 1; i <= n; ++i) {
            int t = i;
            int sum = 0;
            while(t > 0) {
                sum += t % 10;
                t /= 10;
            }
            ++m[sum];
            mx = max(mx, m[sum]);
        }
        int ans = 0;
        for(auto it : m) {
            if(it.second == mx)
                ++ans;
        }
        return ans;
    }
};