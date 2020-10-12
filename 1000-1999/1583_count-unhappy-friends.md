[1583.count-unhappy-friends](https://leetcode.com/problems/count-unhappy-friends/)  

You are given a list of `preferences` for `n` friends, where `n` is always **even**.

For each person `i`, `preferences[i]` contains a list of friends **sorted** in the **order of preference**. In other words, a friend earlier in the list is more preferred than a friend later in the list. Friends in each list are denoted by integers from `0` to `n-1`.

All the friends are divided into pairs. The pairings are given in a list `pairs`, where `pairs[i] = [xi, yi]` denotes `xi` is paired with `yi` and `yi` is paired with `xi`.

However, this pairing may cause some of the friends to be unhappy. A friend `x` is unhappy if `x` is paired with `y` and there exists a friend `u` who is paired with `v` but:

*   `x` prefers `u` over `y`, and
*   `u` prefers `x` over `v`.

Return _the number of unhappy friends_.

**Example 1:**

  
**Input:** n = 4, preferences = \[\[1, 2, 3\], \[3, 2, 0\], \[3, 1, 0\], \[1, 2, 0\]\], pairs = \[\[0, 1\], \[2, 3\]\]  
**Output:** 2  
**Explanation:**  
Friend 1 is unhappy because:  
- 1 is paired with 0 but prefers 3 over 0, and  
- 3 prefers 1 over 2.  
Friend 3 is unhappy because:  
- 3 is paired with 2 but prefers 1 over 2, and  
- 1 prefers 3 over 0.  
Friends 0 and 2 are happy.  

**Example 2:**

  
**Input:** n = 2, preferences = \[\[1\], \[0\]\], pairs = \[\[1, 0\]\]  
**Output:** 0  
**Explanation:** Both friends 0 and 1 are happy.  

**Example 3:**

  
**Input:** n = 4, preferences = \[\[1, 3, 2\], \[2, 3, 0\], \[1, 3, 0\], \[0, 2, 1\]\], pairs = \[\[1, 3\], \[0, 2\]\]  
**Output:** 4  

**Constraints:**

*   `2 <= n <= 500`
*   `n` is even.
*   `preferences.length == n`
*   `preferences[i].length == n - 1`
*   `0 <= preferences[i][j] <= n - 1`
*   `preferences[i]` does not contain `i`.
*   All values in `preferences[i]` are unique.
*   `pairs.length == n/2`
*   `pairs[i].length == 2`
*   `xi != yi`
*   `0 <= xi, yi <= n - 1`
*   Each person is contained in **exactly one** pair.  



**Solution:**  

```cpp
class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ans = 0;
        map<int, int> mp;
        vector<vector<int> > arr(n, vector<int>(n) );
        for(auto &p :pairs) {
            mp[p[0]] = p[1];
            mp[p[1]] = p[0];
            
        }
        for(int k = 0; k < preferences.size(); ++k) {
            auto &p = preferences[k];
            for(int i = 0; i < p.size(); ++i) {
                arr[k][p[i]] = i;
            }
        }
        for(int i1 = 0; i1 < pairs.size(); ++i1) {
            auto &p = pairs[i1];
            int x = p[0], y = p[1];
            bool f = false;
            for(int j1 = 0; j1 < pairs.size(); ++j1) {
                if(i1 == j1) continue;
                int u = pairs[j1][0], v = pairs[j1][1];
                if(arr[x][u] < arr[x][y] && arr[u][x] < arr[u][v]) {
                    f = true;
                    break;
                }
                swap(u, v);
                if(arr[x][u] < arr[x][y] && arr[u][x] < arr[u][v]) {
                    f = true;
                    break;
                }
                    
            }
            ans += f;
            swap(x, y);
            f = false;
            for(int j1 = 0; j1 < pairs.size(); ++j1) {
                if(i1 == j1) continue;
                int u = pairs[j1][0], v = pairs[j1][1];
                if(arr[x][u] < arr[x][y] && arr[u][x] < arr[u][v]) {
                    f = true;
                    break;
                }
                swap(v, u);
                if(arr[x][u] < arr[x][y] && arr[u][x] < arr[u][v]) {
                    f = true;
                    break;
                }
            }
            ans += f;
        }
        return ans;
    }
};
```
      