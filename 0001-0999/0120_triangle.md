[120.triangle](https://leetcode.com/problems/triangle/)  

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

  
\[
  
     \[**2**\],
  
    \[**3**,4\],
  
   \[6,**5**,7\],
  
  \[4,**1**,8,3\]
  
\]
  

The minimum path sum from top to bottom is `11` (i.e., **2** + **3** + **5** + **1** = 11).

**Note:**

Bonus point if you are able to do this using only _O_(_n_) extra space, where _n_ is the total number of rows in the triangle.  



**Solution:**  

```cpp
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
```
      