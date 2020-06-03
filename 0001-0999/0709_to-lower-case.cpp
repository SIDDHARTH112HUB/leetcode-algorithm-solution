//Link: https://leetcode.com/problems/to-lower-case/ 
class Solution {
public:
    string toLowerCase(string str) {
        int diff = 'a'-'A';
        for( char &c : str){
            if( c<='Z' && c>='A'){
                c+=diff;
            }
        }
        return str;
    }
};