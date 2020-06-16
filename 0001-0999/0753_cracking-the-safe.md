[753.cracking-the-safe](https://leetcode.com/problems/cracking-the-safe/)  

There is a box protected by a password. The password is a sequence of `n` digits where each digit can be one of the first `k` digits `0, 1, ..., k-1`.

While entering a password, the last `n` digits entered will automatically be matched against the correct password.

For example, assuming the correct password is `"345"`, if you type `"012345"`, the box will open because the correct password matches the suffix of the entered password.

Return any password of **minimum length** that is guaranteed to open the box at some point of entering it.

**Example 1:**

  
**Input:** n = 1, k = 2  
**Output:** "01"  
**Note:** "10" will be accepted too.  

**Example 2:**

  
**Input:** n = 2, k = 2  
**Output:** "00110"  
**Note:** "01100", "10011", "11001" will be accepted too.  

**Note:**

1.  `n` will be in the range `[1, 4]`.
2.  `k` will be in the range `[1, 10]`.
3.  `k^n` will be at most `4096`.  



**Solution:**  

```cpp
class Solution {
public:
    int n, k;
    string crackSafe(int n, int k) {
        this->n = n;
        this->k = k;
        int total = pow(k, n);
        string ans(n, '0');
        //cout<<ans<<" "<<total<<endl;
        unordered_set<string> visited{ans};
        
        helper(total, visited, ans);
        
        return ans;
    }
    void helper(int total, unordered_set<string> &visited, string &ans){
        if( total <= visited.size() )
            return;
        for( char c='0'+k-1; c>='0'; c--){
            string str = ans.substr(ans.size()-n+1, n-1);
            if( !visited.count(str+c) ){
                ans += c;
                visited.insert(str+c);
                helper(total, visited, ans);
            }
        }
    }
};
```
      