//Link: https://leetcode.com/problems/largest-component-size-by-common-factor/ 
unordered_set<int> dict;
struct UF{
    unordered_map<int, int> m;
    unordered_map<int, int> group;
    int ans = 0;
    int find(int n){
        if( m.count(n) == 0){
            m[n] = n;
            if( dict.count(n) )
                group[n] = 1;
        }
        if( m[n] != n)
            m[n] = find(m[n]);
        return m[n];
    }
    void combine(int a, int b ){
        a = find(a);
        b = find(b);
        if( a != b ){
            m[b] = a;
            group[a] += group[b];
            group.erase(b);
            ans = max(ans, group[a]);
        }
    }
};
class Solution {
public:
    
    UF uf;
    int gcd(int a, int b){
        if( a % b == 0 ){
            return b;
        }
        return gcd( b, a%b);
    }
    
    int largestComponentSize(vector<int>& A) {
        if( A.size() == 0 ) return 0;
        dict = unordered_set<int>(A.begin(), A.end());
        vector<int> p(100001, true);
        p[0] =false;
        p[1] = false;
        vector<int> he;
        vector<int> prime;
        for( int i = 2; i< p.size(); i++ ){
            if( p[i] == false ) continue;
            prime.push_back(i);
            for( int j = i+i; j< p.size(); j+=i){
                p[j] = false;
            }
        }
        for( int i = 0; i<A.size(); i++){
            int num = A[i];
            int n = num;
            for( int j = 2; j*j<=n; j++){
                int p = j;
                while( n % p == 0 ){
                    uf.combine(num, p);
                    n /= p;
                    //j = 0;
                }
                if( n == 1 )
                    break;
            }
            if( n > 1 )
                uf.combine(num, n);
        }
        for( int i = 1; i<A.size(); i++){
            int a = A[i], b = A[i-1];
            int g = gcd( a, b);
            if( g > 1 )
               uf.combine( a, b);
        }
        return uf.ans;
    }
};