//Link: https://leetcode.com/problems/combinations/ 
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combine(int n, int k) {
        if( k == 0 ) return {{}};
        vector<int> item;
        dfs(n, k, 1, item);
        return ans;
    }
    void dfs(int n, int k, int num, vector<int> &item){
        if( k == 0 ){
            ans.push_back(item);
            return;
        }
        if( num > n ) return;
        item.push_back(num);
        dfs(n, k-1, num+1, item);
        item.pop_back();
        
        dfs(n, k, num+1, item);
    }
};