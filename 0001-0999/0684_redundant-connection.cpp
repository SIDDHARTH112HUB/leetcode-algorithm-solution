//Link: https://leetcode.com/problems/redundant-connection/ 
//Template<class T, class CT>
class UnionSet{
    int cnt = 0;
    map<int, int> parent;
public:
    int find( int x ){
        if(x != parent[x])
            return find(parent[x]);
        return x;
    }
    int add(int x){
        if( !parent[x] ){
            parent[x] = x;
            cnt++;
            return x;
        }else{
            return find(x);
        }
    }
    bool combine(int i, int j){
        int x1 = find(i);
        int x2 = find(j);
        if( !x1 )
            x1 = add(i);
        if( !x2 )
            x2 = add(j);
        if( x1 != x2 ){
            parent[x1] = x2;
            cnt--;
            return true;
        }else
            return false;
    }
    int count(){
        return cnt;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionSet us;
        for(auto &e:edges){
            bool res = us.combine(e[0], e[1]);
            if( !res )
                return e;
        }
        return {0,0};
    }
};