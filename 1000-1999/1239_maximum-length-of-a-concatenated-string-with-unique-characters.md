[1239.maximum-length-of-a-concatenated-string-with-unique-characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/)  

Given an array of strings `arr`. String `s` is a concatenation of a sub-sequence of `arr` which have **unique characters**.

Return _the maximum possible length_ of `s`.

**Example 1:**

  
**Input:** arr = \["un","iq","ue"\]  
**Output:** 4  
**Explanation:** All possible concatenations are "","un","iq","ue","uniq" and "ique".  
Maximum length is 4.  

**Example 2:**

  
**Input:** arr = \["cha","r","act","ers"\]  
**Output:** 6  
**Explanation:** Possible solutions are "chaers" and "acters".  

**Example 3:**

  
**Input:** arr = \["abcdefghijklmnopqrstuvwxyz"\]  
**Output:** 26  

**Constraints:**

*   `1 <= arr.length <= 16`
*   `1 <= arr[i].length <= 26`
*   `arr[i]` contains only lower case English letters.  



**Solution:**  

```cpp
class Solution {
public:
    int ans = 0;
    int maxLength(vector<string>& arr) {
        vector<int> v;
        for(auto &str: arr) {
            int num = 0;
            for(auto c : str) {
                if(( (num & ( 1 << (c-'a')) )!= 0)){
                    num = 0;
                    break;
                }
                num |= ( 1 << (c-'a'));
            }
            if(num > 0){
                //cout<<str<<endl;
                v.push_back(num);
            }
        }
        dfs(v, 0, 0);
        return ans;
    }
    int getbits(int num){
        int cnt = 0;
        //cout<<num<<endl;
        while(num > 0) {
            cnt += (num &1);
            num >>= 1;
        }
        //cout<<cnt<<" "<<num<<endl;
        return cnt;
    }
    void dfs(vector<int> &v, int idx, int num) {
        if(idx >= v.size()) {
            ans = max(ans, getbits(num));
            return;
        }
        dfs(v, idx + 1, num);
        if((num & v[idx]) == 0) {
            int nn = num | v[idx];
            dfs(v, idx + 1, nn);
        }
    }
};
```
      