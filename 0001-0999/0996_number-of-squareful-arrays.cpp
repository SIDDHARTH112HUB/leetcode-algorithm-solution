//Link: https://leetcode.com/problems/number-of-squareful-arrays/ 
class Solution {
public:
    bool check( vector<int>& A ){
        for( int i = 0; i< A.size() - 1; i++ ){
            int sq = sqrt(A[i] + A[i+1]);
            if( sq * sq != A[i] + A[i+1])
                return false;
        }
        return true;
    }
    int ans = 0; 
    unordered_map<int, int> count;
    unordered_map<int, unordered_set<int> > sq;
    int numSquarefulPerms(vector<int>& A) {
        for( auto a : A){
            ++count[a];
        }
        for( auto &i : count ){
            for( auto &j : count){
                int x = i.first, y = j.first, s = sqrt(x+y);
                if( s * s == x + y )
                    sq[x].insert(y);
            }   
        }
        for( auto &it : count )
            solve(it.first, A.size()-1);
        return ans;
    }
    
    void solve(int x, int left){
        --count[x];
        if( !left ) ++ans;
        else{
            for( auto y : sq[x]){
                if( count[y] > 0 )
                    solve(y, left-1);
            }
        }
        ++count[x];
    }
};