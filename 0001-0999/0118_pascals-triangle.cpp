//Link: https://leetcode.com/problems/pascals-triangle/ 
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vec;
        if( numRows == 0 )return vec;
        vector<int> tmp;
        tmp.push_back(1);
        vec.push_back(tmp);
        for( int i = 1; i<numRows; i++)
        {
            tmp.clear();
            vec.push_back(tmp);
            vector<int> &t_i= vec[i];
            t_i.push_back(1);
            vector<int> &t= vec[i-1];
            for( int j=1; j<i; j++)
            {
                
                t_i.push_back( t[j-1]+t[j]);
            }
            t_i.push_back(1);
            
        }
        return vec;
    }
};