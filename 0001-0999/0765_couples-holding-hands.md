[765.couples-holding-hands](https://leetcode.com/problems/couples-holding-hands/)  

N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A _swap_ consists of choosing **any** two people, then they stand up and switch seats.

The people and seats are represented by an integer from `0` to `2N-1`, the couples are numbered in order, the first couple being `(0, 1)`, the second couple being `(2, 3)`, and so on with the last couple being `(2N-2, 2N-1)`.

The couples' initial seating is given by `row[i]` being the value of the person who is initially sitting in the i-th seat.

**Example 1:**  

  
**Input:** row = \[0, 2, 1, 3\]
  
**Output:** 1
  
**Explanation:** We only need to swap the second (row\[1\]) and third (row\[2\]) person.
  

**Example 2:**  

  
**Input:** row = \[3, 2, 0, 1\]
  
**Output:** 0
  
**Explanation:** All couples are already seated side by side.
  

**Note:**

1.  `len(row)` is even and in the range of `[4, 60]`.
2.  `row` is guaranteed to be a permutation of `0...len(row)-1`.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_map<int, int> m;
    int minSwapsCouples(vector<int>& row) {
        return dfs(row, 0, 0);
    }
    
    int dfs(vector<int> &row, long long idx, long long mask) {
        if(idx >= row.size()) return 0;
        //if(m.count(mask)) return m[mask];
        if(abs(row[idx] - row[idx+1]) == 1 && max(row[idx], row[idx+1]) % 2) {
            return dfs(row, idx + 2, mask);
        }
        int ans = 0;
        long long src = mask;
        int a = row[idx] % 2 ? row[idx] - 1: row[idx] + 1;
        long long one = 1;
        for(long long i = idx + 2; i < row.size(); ++i) {
            if(row[i] == a) {
                swap(row[i], row[idx + 1]);
                mask |= (one <<(idx+1));
                mask |= (one <<i);
                ans = 1 + dfs(row, idx+ 2, mask);
                swap(row[i], row[idx + 1]);
                mask = src;
                break;
            }
        }
        /*
        a = row[idx+1] % 2 ? row[idx+1] - 1: row[idx+1] + 1;
        for(long long i = idx + 2; i < row.size(); ++i) {
            if(row[i] == a) {
                swap(row[i], row[idx]);
                mask |= (one <<(idx));
                mask |= (one <<i);
                ans = min(ans, 1 + dfs(row, idx+ 2, mask));
                swap(row[i], row[idx]);
                mask =src;
                break;
            }
        }
        m[src] = ans;*/
        return ans;
    }
};
```
      