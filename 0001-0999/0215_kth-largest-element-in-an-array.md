[215.kth-largest-element-in-an-array](https://leetcode.com/problems/kth-largest-element-in-an-array/)  

Find the **k**th largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

**Example 1:**

**Input:** `[3,2,1,5,6,4]` and k = 2
**Output:** 5

**Example 2:**

**Input:** `[3,2,3,1,2,4,5,5,6]` and k = 4
**Output:** 4

**Note:**  
You may assume k is always valid, 1 ≤ k ≤ array's length.  



**Solution:**  

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //auto mptr = nums.begin() + nums.size()-k;
        //nth_element(nums.begin(), mptr, nums.end());
        //return *mptr;
        int l = 0, r = nums.size()-1;
        while(true){
            int pos = partition(nums, l, r);
            if( pos == k-1) return nums[pos];
            else if( pos >k-1) r = pos-1;
            else l = pos+1;
        }
        return -1;
    }
    int partition(vector<int>& nums, int l, int r){
        int pivot = nums[l];
        int left = l;
        l=l+1;
        while(l<=r){
            if( nums[l] < pivot && nums[r] >pivot){
                swap(nums[l++], nums[r--]);
            }
            if( nums[l] >= pivot )++l;
            if( nums[r] <= pivot)--r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
```
      