//Link: https://leetcode.com/problems/combination-sum-iii/ 
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> item;
        solve(k, n, 1, item);
        return ans;
    }
    
    void solve( int k , int n, int idx, vector<int> &item){
        if( n < 0 )
            return;
        if( k == 0 ){
            if( n == 0 )
                ans.push_back(item);
            return;
        }
        for( int i = idx; i<=9; i++){
            item.push_back(i);
            solve( k-1, n-i, i+1, item);
            item.pop_back();
        }
    }
};