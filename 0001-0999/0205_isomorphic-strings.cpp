//Link: https://leetcode.com/problems/isomorphic-strings/ 
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int, int> m1, m2;
        for(int i = 0; i<s.size(); i++){
            if( m1[s[i]] == 0 && m2[t[i]] == 0 ){
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
            else if( m1[s[i]] != t[i] )
                return false;
            else if( m2[t[i]] != s[i] )
                return false;
        }
        return true;
    }
};