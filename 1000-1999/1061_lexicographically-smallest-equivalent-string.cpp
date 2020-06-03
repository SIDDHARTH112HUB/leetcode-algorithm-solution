//Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/ 
struct UF {
    map<int, int> m;
    int find(int x) {
        if(m.count(x)){
            return m[x] == x ? x : (m[x] = find(m[x]));
        }
        return m[x] = x;
    }
    void combine(int a, int b) {
        a = find(a);
        b = find(b);
        m[max(a, b)] = min(a, b);
    }
};
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        UF uf;
        for(int i = 0; i < A.size(); ++i)
            uf.combine(A[i], B[i]);
        string ans;
        for(auto c : S)
            ans += uf.find(c);
        return ans;
    }
};