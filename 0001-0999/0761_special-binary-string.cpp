//Link: https://leetcode.com/problems/special-binary-string/ 
class Solution {
public:
    set<string> res;
    string makeLargestSpecial(string S) {
        vector<string> dict;
        string res;
        int i = 0, j = 0, cnt = 0;
        for( ; i < S.size(); i++){
            cnt += ( S[i] == '1' ? 1:-1 );
            if( cnt == 0 ){
                dict.push_back( '1' + makeLargestSpecial(S.substr( j+1, i-j -1)) + '0');
                j = i + 1;
            }
        }
        sort(dict.begin(), dict.end(), greater<string>() );
        for( auto &str: dict)
            res += str;
        return res;
    }
};