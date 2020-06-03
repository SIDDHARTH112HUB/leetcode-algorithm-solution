//Link: https://leetcode.com/problems/permutation-in-string/ 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int begin = 0, end = 0,counter = 0;
        int hash[256] = {0};
        for( char c:s1)
            hash[c]++;
        while(end<s2.size()){
            if( hash[s2[end++]]-- == 0 ) counter++;
            while( counter > 0 ){
                if( hash[s2[begin++]]++ < 0 )counter--;
            }
            if( counter == 0 && end-begin >= s1.size() )
                return true;
        }
        return false;
    }
};