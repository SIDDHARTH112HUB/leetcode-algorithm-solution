//Link: https://leetcode.com/problems/smallest-string-with-swaps/ 
struct UF{
    unordered_map<int, int> m;
    
    int find(int x) {
        if(m.count(x)) {
            return m[x] == x ? x : (m[x] = find(m[x]));
        }
        return m[x] = x;
    }
    void combine(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            m[b] = a;
        }
    }
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_set<int> v;
        UF uf;
        for(auto &p : pairs) {
            uf.combine(p[0], p[1]);
        }
        unordered_map<int, string> m;
        unordered_map<int, int> midx;
        for(int i = 0; i < s.size(); ++i) {
            if(uf.m.count(i)) {
                int g = uf.find(i);
                m[g] += s[i];
            }
        }
        for(auto &it : m) {
            sort(it.second.begin(), it.second.end());
            //reverse(it.second.begin(), it.second.end());
        }
        string ans;
        
        for(int i = 0; i < s.size(); ++i) {
            if(uf.m.count(i)) {
                int g = uf.find(i);
                ans += m[g][midx[g]];
                ++midx[g];
            }else{
                ans += s[i];
            }
        }
        return ans;
    }
};