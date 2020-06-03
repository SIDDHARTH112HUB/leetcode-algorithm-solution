//Link: https://leetcode.com/problems/maximal-rectangle/ 
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if( m == 0 ) return 0;
        int n = matrix[0].size();
        if( n == 0 ) return 0;
        vector<int> h(n+1);
        h[n] = -1;
        int ans = 0;
        for( int i = 0; i<m; i++){
            for( int j = 0; j<n; j++){
                if( matrix[i][j] == '1'){
                    h[j]++;
                }else{
                    h[j]=0;
                }
            }
            ans = max(ans, maxHistogram(h));
        }
        return ans;
    }
    
    int maxHistogram(vector<int> &h){
        int ans = 0;
        stack<pair<int, int> > stk;
        for( int i = 0; i<h.size(); i++){
            while( stk.size() && stk.top().first > h[i]){
                int prev_h = stk.top().first;
                stk.pop();    
                int prev_idx = 0;
                if( stk.size() )
                    prev_idx = stk.top().second+1;
                ans = max( prev_h *(i-prev_idx), ans);
            }
            stk.push({h[i], i});
        }
        return ans;
    }
};