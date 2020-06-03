//Link: https://leetcode.com/problems/valid-anagram/ 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() ) return false;
        int hash[128] = {0};
        for( char c : s)
            ++hash[c];
        for( char c:t)
            if( hash[c]-- == 0 )
                return false;
        return true;
    }
};