[60.permutation-sequence](https://leetcode.com/problems/permutation-sequence/)  

The set `[1,2,3,...,_n_]` contains a total of _n_! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for _n_ = 3:

1.  `"123"`
2.  `"132"`
3.  `"213"`
4.  `"231"`
5.  `"312"`
6.  `"321"`

Given _n_ and _k_, return the _k_th permutation sequence.

**Note:**

*   Given _n_ will be between 1 and 9 inclusive.
*   Given _k_ will be between 1 and _n_! inclusive.

**Example 1:**

  
**Input:** n = 3, k = 3
  
**Output:** "213"
  

**Example 2:**

  
**Input:** n = 4, k = 9
  
**Output:** "2314"  



**Solution:**  

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f = vector<int>(n, 1);
        string num = "123456789";
        string ans = "";
        
        for( int i = 1; i<n; i++) f[i] = f[i-1]*i;
        --k;
        for( int i =n-1; i>=0; i--){
            int digit = k/f[i];
            k = k%f[i];
            ans.push_back(num[digit]);
            num.erase(digit,1);
        }
        return ans;
    }
};
```
      