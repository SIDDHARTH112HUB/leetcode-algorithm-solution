//Link: https://leetcode.com/problems/grumpy-bookstore-owner/ 
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        vector<int> pc(customers.size());
        for(int i = 0; i < grumpy.size(); ++i){
            if(grumpy[i] == 1)
                pc[i] = i > 0 ? pc[i-1] : 0;
            else
                pc[i] += customers[i] + (i > 0 ? pc[i-1] : 0);
            customers[i] += i > 0 ? customers[i-1] : 0;
        }
        int n = grumpy.size();
        int ans = pc.back();
        for(int i = 0; i < grumpy.size(); ++i) {
            if(grumpy[i] == 1) {
                int r = i + X - 1 >= n - 1 ? n - 1 : i + X - 1;
                int z = (i > 0 ? pc[i-1]:0) + pc[n-1] - pc[r];
                ans = max(ans, customers[r] - (i > 0 ? customers[i-1] : 0) + z);
            }
        }
        return ans;
    }
};