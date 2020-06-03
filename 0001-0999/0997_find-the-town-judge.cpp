//Link: https://leetcode.com/problems/find-the-town-judge/ 
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> count(N+1);
        for( auto &t: trust){
            count[t[0]] = -1;
            if( count[t[1]] != -1 )
                ++count[t[1]];
        }
        for( int i = 1; i < count.size(); i++)
            if( count[i] == N-1)
                return i;
        return -1;
    }
};