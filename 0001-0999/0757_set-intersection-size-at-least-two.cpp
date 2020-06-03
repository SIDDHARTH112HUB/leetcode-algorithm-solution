//Link: https://leetcode.com/problems/set-intersection-size-at-least-two/ 
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            if( a[1] == b[1] ) return a[0] > b[0];
            return a[1] < b[1];
        });
        vector<int> ans = {-1,-1};
        for( auto &i:intervals ){
            if( i[0] <= ans[ans.size()-2])continue;
            if( i[0] > ans.back() ) ans.push_back(i[1]-1);
            ans.push_back(i[1]);
        }
        return ans.size() - 2;
    }
};