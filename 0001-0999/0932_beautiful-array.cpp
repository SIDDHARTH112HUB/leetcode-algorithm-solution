//Link: https://leetcode.com/problems/beautiful-array/ 
class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> ans = {1};
        while( ans.size() < N ){
            vector<int> tmp;
            for( auto n : ans) if( n * 2-1<=N)tmp.push_back( n*2-1);
            for( auto n : ans)  if( n * 2<=N)tmp.push_back( n * 2);
            ans =tmp;
        }
        return ans;
    }
};