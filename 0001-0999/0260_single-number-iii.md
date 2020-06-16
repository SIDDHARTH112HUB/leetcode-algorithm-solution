[260.single-number-iii](https://leetcode.com/problems/single-number-iii/)  

Given an array of numbers `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

**Example:**

  
**Input:**  `[1,2,1,3,2,5]`
  
**Output:** `[3,5]`

**Note**:

1.  The order of the result is not important. So in the above example, `[5, 3]` is also correct.
2.  Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> vec;
        if( nums.size() == 0 )
            return vec;
        int x = 0;
        for( auto iter = nums.begin(); iter!= nums.end(); iter++){
            x ^= (*iter);
        }
        
        int last = x & ( ~(x - 1) );
        int a = 0;
        int b = 0;
        for( auto iter = nums.begin(); iter!= nums.end(); iter++){
            if( (last & (*iter)) == 0 ){
                a ^= (*iter);
            }
            else{
                b ^= (*iter);
            }
        }
        vec.push_back(a);
        vec.push_back(b);
        return vec;
    }
};
```
      