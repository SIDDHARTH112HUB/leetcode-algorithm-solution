//Link: https://leetcode.com/problems/repeated-string-match/ 
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string t = A;
        int cnt = 1;
        while( t.size() < B.size()){
            t+=A;
            cnt++;
        }
        int i = t.find(B);
        if( i != string::npos ) return cnt;
        t+=A;
        i = t.find(B);
        cnt++;
        if( i != string::npos ) return cnt;
        return -1;
    }
};