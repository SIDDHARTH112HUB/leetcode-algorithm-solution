//Link: https://leetcode.com/problems/group-anagrams/ 
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > m;
        for( int i = 0; i < strs.size(); i++ )
        {
            string s = strs[i];
            sort( s.begin(), s.end());
            m[s].push_back( strs[i] );
            
        }
        vector<string> res;
        for( map<string, vector<string> >::iterator iter = m.begin(); iter!=m.end(); ++iter )
        {
            if( iter->second.size()>1 )
            {
                for( int i = 0; i < iter->second.size(); i++)
                {
                    res.push_back( iter->second[i]);
                }
            }
        }
        return res;
    }
};