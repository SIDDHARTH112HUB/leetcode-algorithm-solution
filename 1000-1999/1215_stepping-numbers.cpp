//Link: https://leetcode.com/problems/stepping-numbers/ 
class Solution {
public:
    vector<int> ans;
    vector<int> countSteppingNumbers(int low, int high) {
        for(int i = 0; i <= 9; ++i) {
            helper(low, high, i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void helper(long long low, long long high, long long target) {
        queue<long long> q;
        q.push(target);
        while(q.size()) {
            long long num = q.front();
            q.pop();
            if(num >= low && num <= high)
                ans.push_back(num);
            if(num == 0 || num >= high) continue;
            long long mod = num % 10;
            long long n1 = num * 10 + (mod + 1);
            long long n2 = num * 10 + (mod - 1);
            if(mod != 0) 
                q.push(n2);
            if(mod != 9)
                q.push(n1);
        }
    }
};