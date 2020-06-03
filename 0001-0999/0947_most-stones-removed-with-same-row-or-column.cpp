//Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/ 
class Solution {
public:
    unordered_map<int, int > m;
    int islands = 0;
    int find(int x){
        if( m.count(x) == 0 ) m[x]=x, islands++;
        if( m[x] != x ) m[x] = find(m[x]);
        return m[x];
    }
    void uni(int x, int y){
        x = find(x);
        y = find(y);
        if( x != y ) m[x] = y, islands--;
    }
    int removeStones(vector<vector<int>>& stones) {
        for( auto &s: stones){
            uni(s[0], ~s[1]);
        }
        return stones.size() - islands;
    }
};