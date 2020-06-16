[119.pascals-triangle-ii](https://leetcode.com/problems/pascals-triangle-ii/)  

Given a non-negative index _k_ where _k_ ≤ 33, return the _k_th index row of the Pascal's triangle.

Note that the row index starts from 0.

![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)  
In Pascal's triangle, each number is the sum of the two numbers directly above it.

**Example:**

  
**Input:** 3
  
**Output:** \[1,3,3,1\]
  

**Follow up:**

Could you optimize your algorithm to use only _O_(_k_) extra space?  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if( rowIndex <= 0 ) return {1};
        vector<int> ans(rowIndex+1);
        ans[0] = 1;
        for( int i = 1; i<=rowIndex; i++){
            for( int j = i; j>=1; j--){
                ans[j] = ans[j] + ans[j-1];
            }
        }
        return ans;
    }
};
```
      