//Link: https://leetcode.com/problems/longest-common-prefix/ 
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        int size = strs.size();
        if( size == 0)
            return res;
        if( size == 1)
            return strs[0];
        int len = strs[0].length();
        for( int i = 1; i<size; i++)
        {
            if( len > strs[i].length())
                len = strs[i].length();
        }
        for( int i = 0; i<len; i++)
        {
            char a = strs[0].at(i);
            for( int j = 1; j<size; j++)
            {
                if( a != strs[j].at(i))
                    return res;
            }
            res.append(1, a);
        }
        return res;
    }
};