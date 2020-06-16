[503.next-greater-element-ii](https://leetcode.com/problems/next-greater-element-ii/)  

Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

**Example 1:**  

  
**Input:** \[1,2,1\]
  
**Output:** \[2,-1,2\]
  
**Explanation:** The first 1's next greater number is 2;   
The number 2 can't find next greater number;   
The second 1's next greater number needs to search circularly, which is also 2.
  

**Note:** The length of given array won't exceed 10000.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        vector<int> arr;
        vector<int> ans(nums2.size(), -1);
        unordered_map<int, int> m;
        for(int i = 0; i < nums2.size() *2; ++i) {
            int idx = i % nums2.size();
            int num = nums2[idx];
            while(arr.size() && nums2[arr.back()] < num) {
                ans[arr.back()] = num;
                arr.pop_back();
            }
            if(i < nums2.size())
                arr.push_back(i);
        }
        return ans;
    }
};
```
      