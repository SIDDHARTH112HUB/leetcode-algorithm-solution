//Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/ 
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if( k < 0 ) return 0;
        map<int, int> m;
        int ans = 0;
        for( int n : nums ){
            if( k == 0 && m[n] == 1)
                ans++;
            ++m[n];
        }
        if( k == 0 )return ans;
        for( auto n : m ){
            if( m.count(n.first + k) )
                ++ans;
        }
        return ans;
    }
};