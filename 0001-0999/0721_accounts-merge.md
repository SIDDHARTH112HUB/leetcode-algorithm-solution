[721.accounts-merge](https://leetcode.com/problems/accounts-merge/)  

Given a list `accounts`, each element `accounts[i]` is a list of strings, where the first element `accounts[i][0]` is a _name_, and the rest of the elements are _emails_ representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails **in sorted order**. The accounts themselves can be returned in any order.

**Example 1:**  

  
**Input:** 
  
accounts = \[\["John", "johnsmith@mail.com", "john00@mail.com"\], \["John", "johnnybravo@mail.com"\], \["John", "johnsmith@mail.com", "john\_newyork@mail.com"\], \["Mary", "mary@mail.com"\]\]
  
**Output:** \[\["John", 'john00@mail.com', 'john\_newyork@mail.com', 'johnsmith@mail.com'\],  \["John", "johnnybravo@mail.com"\], \["Mary", "mary@mail.com"\]\]
  
**Explanation:** 
  
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
  
The second John and Mary are different people as none of their email addresses are used by other accounts.
  
We could return these lists in any order, for example the answer \[\['Mary', 'mary@mail.com'\], \['John', 'johnnybravo@mail.com'\], 
  
\['John', 'john00@mail.com', 'john\_newyork@mail.com', 'johnsmith@mail.com'\]\] would still be accepted.
  

**Note:**

*   The length of `accounts` will be in the range `[1, 1000]`.
*   The length of `accounts[i]` will be in the range `[1, 10]`.
*   The length of `accounts[i][j]` will be in the range `[1, 30]`.  



**Solution:**  

```cpp


class Solution {
public:
    map<string, string> m;
    map<string, string> owner;
    map<string, vector<string> > group;
    string find(const string &a) {
        if(m.count(a))
            return a == m[a] ? a : (m[a] = find(m[a]));
        return m[a] = a;
    }
    
    void un(string &a, string &b) {
        m[find(b)] = find(a);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto &l : accounts) {
            for(int i = 1; i < l.size(); ++i) {
                owner[l[i]] = l[0];
                un(l[i], l[i+1 >= l.size() ? i : (i + 1 )]);
            }
        }
        for(auto it : m) {
            group[find(it.first)].push_back(it.first);
        }
        vector<vector<string> > ans;
        for(auto it : group) {
            sort(it.second.begin(), it.second.end());
            ans.push_back({owner[it.first]});
            for(auto &a : it.second) {
                ans.back().push_back(a);
            }
        }
        return ans;
    }
};
```
      