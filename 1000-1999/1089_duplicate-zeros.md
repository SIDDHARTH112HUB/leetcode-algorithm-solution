[1089.duplicate-zeros](https://leetcode.com/problems/duplicate-zeros/)  

Given a fixed length array `arr` of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array **in place**, do not return anything from your function.

**Example 1:**

  
**Input:** \[1,0,2,3,0,4,5,0\]
  
**Output:** null
  
**Explanation:** After calling your function, the **input** array is modified to: \[1,0,0,2,3,0,0,4\]
  

**Example 2:**

  
**Input:** \[1,2,3\]
  
**Output:** null
  
**Explanation:** After calling your function, the **input** array is modified to: \[1,2,3\]
  

**Note:**

1.  `1 <= arr.length <= 10000`
2.  `0 <= arr[i] <= 9`  



**Solution:**  

```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> a1;
        for(auto n : arr){
            a1.push_back(n);
            if(n == 0)
                a1.push_back(n);
        }
        for(int i = 0; i < arr.size(); ++i){
            arr[i] = a1[i];
        }
    }
};
```
      