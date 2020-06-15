[118.pascals-triangle](https://leetcode.com/problems/pascals-triangle/)  

Given a non-negative integer _numRows_, generate the first _numRows_ of Pascal's triangle.

![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)  
In Pascal's triangle, each number is the sum of the two numbers directly above it.

**Example:**

**Input:** 5
**Output:**
\[
     \[1\],
    \[1,1\],
   \[1,2,1\],
  \[1,3,3,1\],
 \[1,4,6,4,1\]
\]  



**Solution:**  

```cpp
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
```
      