//Link: https://leetcode.com/problems/triangle/ 
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size = triangle.size();
        if( size == 0 ) return 0;
        if( size == 1 ) return triangle[0][0];
        
        for( int i = 1; i<size; i++)
        {
            vector<int>& vec = triangle[i];
            vec[0] += triangle[i-1][0];
            vec[vec.size()-1] += triangle[i-1][triangle[i-1].size()-1];
            for( int j = 1; j<vec.size()-1; j++)
            {
                int left  = triangle[i-1][j-1];
                int right = triangle[i-1][j];
                vec[j] += (left>right?right:left);
            }
        }
        vector<int>& last_vec = triangle[size-1];
        return *std::min_element( last_vec.begin(), last_vec.end() );
    }
};