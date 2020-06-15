[386.lexicographical-numbers](https://leetcode.com/problems/lexicographical-numbers/)  

Given an integer _n_, return 1 - _n_ in lexicographical order.

For example, given 13, return: \[1,10,11,12,13,2,3,4,5,6,7,8,9\].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> ans;
    int n;
    vector<int> lexicalOrder(int _n) {
        n = _n;
        for(int i =1; i <=9; ++i) {
            dfs(i);
        }
        return ans;
    }
    
    void dfs(int num) {
        if(num > n) return;
        ans.push_back(num);
        for(int i = 0; i <=9; ++i) {
            dfs(num * 10 + i);
        }
    }
};
```
      