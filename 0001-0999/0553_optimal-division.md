[553.optimal-division](https://leetcode.com/problems/optimal-division/)  

Given a list of **positive integers**, the adjacent integers will perform the float division. For example, \[2,3,4\] -> 2 / 3 / 4.

However, you can add any number of parenthesis at any position to change the priority of operations. You should find out how to add parenthesis to get the **maximum** result, and return the corresponding expression in string format. **Your expression should NOT contain redundant parenthesis.**

**Example:**  

  
**Input:** \[1000,100,10,2\]
  
**Output:** "1000/(100/10/2)"
  
**Explanation:**
  
1000/(100/10/2) = 1000/((100/10)/2) = 200
  
However, the bold parenthesis in "1000/(**(**100/10**)**/2)" are redundant,   
since they don't influence the operation priority. So you should return "1000/(100/10/2)". 
  

  
Other cases:
  
1000/(100/10)/2 = 50
  
1000/(100/(10/2)) = 50
  
1000/100/10/2 = 0.5
  
1000/100/(10/2) = 2
  

**Note:**

1.  The length of the input array is \[1, 10\].
2.  Elements in the given array will be in range \[2, 1000\].
3.  There is only one optimal division for each test case.  



**Solution:**  

```cpp
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        
        
        if(nums.size() == 1) return to_string(nums[0]);;
        string r;
        for(int i = 1; i < nums.size(); ++i ) {
            r += to_string(nums[i]) + "/";
        }
        r.pop_back();
        if(nums.size() > 2){
            r = "("+r+")";
        }
        return to_string(nums[0]) + "/" + r;
    }
};
```
      