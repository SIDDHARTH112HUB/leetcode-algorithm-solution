//Link: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/ 
int gcd(int n, int m){
    if( n == 0 ) return m;
    if( m == 0 ) return n;
    if( n % m == 0 ) return m;
    return gcd(m, n % m);
}
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if( deck.size() <= 1 ) return false;
        unordered_map<int, int> m;
        for( int n : deck)
            m[n]++;
        if( m.size() == 1 ) return true;
        vector<int> v;
        for( auto it : m ){
            v.push_back(it.second);
        }
        //sort(v.begin(), v.end());
        int g = gcd(v[1], v[0]);
        if( g <= 1 ) return false;
        for( int i = 2; i<v.size(); i++){
            g = gcd(v[i], g);
            if( g <= 1 )
                return false;
        }
        return true;
    }
};