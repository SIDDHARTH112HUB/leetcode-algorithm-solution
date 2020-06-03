//Link: https://leetcode.com/problems/factor-combinations/ 
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> getFactors(int n) {
        vector<int> item;
        dfs(n, 2, item);
        return ans;
    }
    
    void dfs(int n, int start, vector<int> &item) {
        for(int i = start; i * i <= n; ++i) {
            if(n % i == 0) {
                if(n / i < i) continue;
                item.push_back(i);
                item.push_back(n / i);
                ans.push_back(item);
                item.pop_back(); item.pop_back();
                item.push_back(i);
                dfs(n / i, i, item);
                item.pop_back();
            }
        }
    }
};