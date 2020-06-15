[1133.largest-unique-number](https://leetcode.com/problems/largest-unique-number/)  

Given an array of integers `A`, return the largest integer that only occurs once.

If no integer occurs once, return -1.

**Example 1:**

**Input:** \[5,7,3,9,4,9,8,3,1\]
**Output:** 8
**Explanation:** 
The maximum integer in the array is 9 but it is repeated. The number 8 occurs only once, so it's the answer.

**Example 2:**

**Input:** \[9,9,8,8\]
**Output:** \-1
**Explanation:** 
There is no number that occurs only once.

**Note:**

1.  `1 <= A.length <= 2000`
2.  `0 <= A[i] <= 1000`  



**Solution:**  

```cpp
class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        if(A.size() == 1) return A[0];
        map<int, int> m;
        for(auto n: A)
            ++m[n];
        for(auto it=m.rbegin(); it!=m.rend(); ++it){
            if(it->second == 1)
                return it->first;
        }
        return -1;
    }
};
```
      