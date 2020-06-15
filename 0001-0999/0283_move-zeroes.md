[283.move-zeroes](https://leetcode.com/problems/move-zeroes/)  

Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Example:**

**Input:** `[0,1,0,3,12]`
**Output:** `[1,3,12,0,0]`

**Note**:

1.  You must do this **in-place** without making a copy of the array.
2.  Minimize the total number of operations.  



**Solution:**  

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        for( int i = 0; i < size; i++ ){
            if( nums[i] == 0 )
                ++count;
            else
                nums[i-count] = nums[i];
        }
        while(count>0){
            nums[size-count]=0;
            count--;
        }
    }
};
```
      