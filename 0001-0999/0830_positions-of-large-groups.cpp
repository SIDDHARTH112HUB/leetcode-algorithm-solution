//Link: https://leetcode.com/problems/positions-of-large-groups/ 
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        char prev = ' ';
        int last = 0;
        int cnt = 1;
        int idx=0;
        vector< vector<int> > ans;
        for( char c : S){
            if( prev == c ){
                cnt++;
            }else{
                if( cnt >= 3 ){
                    ans.push_back({last, idx-1});
                }
                prev = c;
                cnt = 1;
                last = idx;
            }
            idx++;
        }
        if( cnt >= 3 ){
            ans.push_back({last, idx-1});
        }
        return ans;
    }
};