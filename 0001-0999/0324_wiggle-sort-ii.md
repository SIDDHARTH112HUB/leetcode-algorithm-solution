[324.wiggle-sort-ii](https://leetcode.com/problems/wiggle-sort-ii/)  

Given an unsorted array `nums`, reorder it such that `nums[0] < nums[1] > nums[2] < nums[3]...`.

**Example 1:**

**Input:** `nums = [1, 5, 1, 1, 6, 4]`
**Output:** One possible answer is `[1, 4, 1, 5, 1, 6]`.

**Example 2:**

**Input:** `nums = [1, 3, 2, 2, 3, 1]`
**Output:** One possible answer is `[2, 3, 1, 3, 1, 2]`.

**Note:**  
You may assume all input has valid answer.

**Follow Up:**  
Can you do it in O(n) time and/or in-place with O(1) extra space?  



**Solution:**  

```cpp
class Solution {
public:
    
    void wiggleSort(vector<int>& nums) {
        
        int size = nums.size();
        if( size <= 1) return;
        auto mptr = nums.begin() + (size-1)/2;
        nth_element(nums.begin(), mptr, nums.end());
        int mid = *mptr;
        int i = 1;
        int j = ((size-1) & 1) ? size-2:size-1;
        //cout<<mid<<endl;
        for( int k=0; k<size; ++k){
            if( nums[k] > mid && i <size ){
                if( k <= i && (k & 1 ) ) continue;
                swap(nums[k--], nums[i]);
                i += 2;
            }else if( nums[k] < mid && j>=0 ){
                if( k >= j && (k & 1 ) == 0 ) continue;
                swap(nums[k--], nums[j]);
                j -= 2;
            }
        }
    }
};
```
      