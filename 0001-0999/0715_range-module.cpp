//Link: https://leetcode.com/problems/range-module/ 
class RangeModule {
public:
    RangeModule() {
        
    }
    map<int, int> m;
    void addRange(int left, int right) {
        
        auto pos = find(left, right);
        m[pos.first] = pos.second;
    }
    
    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if( it == m.begin())return false;
        --it;
        return it->second >=right;
    }
    
    void removeRange(int left, int right) {
        if( m.size() == 0 ) return;
        auto x = find(left, right);
        if( left > x.first ) m[x.first] = left;
        if( right < x.second ) m[right ] = x.second;
    }
    
    pair<int, int> find( int left, int right){
        auto l = m.upper_bound(left);
        auto r = m.upper_bound(right);
        if( l != m.begin() && (--l)->second < left ) ++l;
        if( l == r )return {left, right};
        int i = min(l->first, left), j =max( (--r)->second, right );
        m.erase(l, ++r);
        return {i,j};
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */