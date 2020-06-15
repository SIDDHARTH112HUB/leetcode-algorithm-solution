[93.restore-ip-addresses](https://leetcode.com/problems/restore-ip-addresses/)  

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

**Example:**

**Input:** "25525511135"
**Output:** `["255.255.11.135", "255.255.111.35"]`  



**Solution:**  

```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) {
        vector<string> item;
        dfs(s, 0, item);    
        return ans;
    }
    
    void dfs(string &s, int idx, vector<string> &item){
        long long num = 0;
        if( item.size() == 4 ){
            if( s.size() == idx ){
                string str = "";
                for( auto &i:item){
                    str+=i;
                    str+='.';
                }
                str.pop_back();
                ans.push_back(str);
            }
            return;
        }
        string str = "";
        for(int i = idx; i<s.size(); i++){
            if( num == 0 && s[i] == '0'){
                item.push_back("0");
                dfs(s, i+1, item);
                item.pop_back();
                break;
            }
            num = num*10 + (s[i]-'0');
            if( num <= 255 ){
                str += s[i];
                item.push_back(str);
                dfs(s, i+1, item);
                item.pop_back();
            }
        }
    }
    
};
```
      