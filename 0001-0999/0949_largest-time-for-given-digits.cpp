//Link: https://leetcode.com/problems/largest-time-for-given-digits/ 
class Solution {
public:
    int ans = -1;
    string largestTimeFromDigits(vector<int>& A) {
        dfs(A, 0, 0, 0);
        if( ans == -1 )
            return ""; 
        string h = to_string(ans >> 8);
        if( h.size() == 1 )
            h = "0"+h;
        string m = to_string( ans & 0xFF);
        if( m.size() == 1 )
            m = "0"+m;
        return h + ":" + m;
    }
    void dfs( vector<int>& A, int h, int m, int cnt){
        if( cnt >= 4 ){
            ans = max(ans, (h<<8)+m);
            return;
        }
        for( int i = 0; i< A.size(); i++){
            if( A[i] == -1) continue;
            int src = A[i];
            if( h*10 + A[i] <24){
                int newh = h*10 + A[i];
                A[i] = -1;
                dfs( A, newh, m, cnt+1);
                A[i] = src;
            }else if( m *10 + A[i] < 60 ){
                int newm = m*10 + A[i];
                A[i] = -1;
                dfs( A, h, newm, cnt+1);
                A[i] = src;
            }
        }
    }
};