//Link: https://leetcode.com/problems/similar-string-groups/ 
class Union{
public:
    int cnt = 0;
    map<int, int> parent;
public:
    Union(vector<string>& A){
        cnt = A.size();
        for( int i = 0; i<A.size(); i++){
            this->add(i+1);
        }
    }
    void add(int i){
        if( !parent[i] )
            parent[i] = i;
    }
    int find( int i){
        if( parent[i] != i )
            i = find(parent[i]);
        return i;
    }
    void combine(int i, int j){
        i = find(i);
        j = find(j);
        if( i != j ){
            parent[i] = j;
            cnt--;
        }
    }
    int count(){
        return this->cnt;
    }
};

class Solution {
public:
    bool check(string &a, string& b){
        int cnt = 0;
        for( int i = 0; i<a.size();i++){
            if( a[i] != b[i] ){
                cnt++;
                if( cnt > 2 )
                    return false;
            }
        }
        return true;
    }
    int numSimilarGroups(vector<string>& A) {
        int length = A.size();
        Union un(A);
        for( int i = 0; i<length; i++){
            for(int j = i+1; j<length; j++){
                if( check(A[i], A[j])){
                    un.combine(i+1, j+1);
                }
            }
        }
        return un.count();
    }
};