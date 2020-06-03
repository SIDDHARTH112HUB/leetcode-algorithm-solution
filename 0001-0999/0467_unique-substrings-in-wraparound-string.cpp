//Link: https://leetcode.com/problems/unique-substrings-in-wraparound-string/ 
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> vec(26);
        int len = 1;
        for( int i = p.size()-1; i>=0; i--){
            
            if( i <p.size()-1 && (( p[i+1] - 1 == p[i]) || ( p[i+1] == 'a' && p[i] == 'z' ) ) ){
                len += 1;
            }else{
                len = 1;
            }
            vec[p[i]-'a'] = max(vec[p[i]-'a'], len);
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};