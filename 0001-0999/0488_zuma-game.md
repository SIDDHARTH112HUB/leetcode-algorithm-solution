[488.zuma-game](https://leetcode.com/problems/zuma-game/)  

Think about Zuma Game. You have a row of balls on the table, colored red(R), yellow(Y), blue(B), green(G), and white(W). You also have several balls in your hand.

Each time, you may choose a ball in your hand, and insert it into the row (including the leftmost place and rightmost place). Then, if there is a group of 3 or more balls in the same color touching, remove these balls. Keep doing this until no more balls can be removed.

Find the minimal balls you have to insert to remove all the balls on the table. If you cannot remove all the balls, output -1.

**Example 1:**

  
**Input:** board = "WRRBBW", hand = "RB"  
**Output:** -1  
**Explanation:** WRRBBW -> WRR\[R\]BBW -> WBBW -> WBB\[B\]W -> WW  

**Example 2:**

  
**Input:** board = "WWRRBBWW", hand = "WRBRW"  
**Output:** 2  
**Explanation:** WWRRBBWW -> WWRR\[R\]BBWW -> WWBBWW -> WWBB\[B\]WW -> WWWW -> empty  

**Example 3:**

  
**Input:** board = "G", hand = "GGGGG"  
**Output:** 2  
**Explanation:** G -> G\[G\] -> GG\[G\] -> empty   

**Example 4:**

  
**Input:** board = "RBYYBBRRB", hand = "YRBGB"  
**Output:** 3  
**Explanation:** RBYYBBRRB -> RBYY\[Y\]BBRRB -> RBBBRRB -> RRRB -> B -> B\[B\] -> BB\[B\] -> empty   

**Constraints:**

*   You may assume that the initial row of balls on the table won’t have any 3 or more consecutive balls with the same color.
*   `1 <= board.length <= 16`
*   `1 <= hand.length <= 5`
*   Both input strings will be non-empty and only contain characters 'R','Y','B','G','W'.  



**Solution:**  

```cpp
class Solution {
public:
    string merge(string s) {
        int prev = 0;
        for(int i = 1; i < s.size(); ++i) {
            if(s[i] != s[i-1] || i + 1 == s.size()) {
                int cur = s[i] == s[i-1] ? i : i-1;
                if(cur - prev >= 2) 
                    return merge(s.substr(0, prev) + s.substr(cur + 1));
                prev = i;
            }
        }
        return s;
    }
    int findMinStep(string board, string hand) {
        //cout<<"begin "<<board<<endl<<endl;
        vector<int> hm(128);
        for(auto c : hand)
            ++hm[c];
        int res = dfs(board, hm);
        return res >= 10000 ? -1 : res;
    }
    int dfs(string board, vector<int> &hm) {
        if(board.size() == 0) return 0;
        int ans = 10000;
        for(int i = 0; i < board.size(); ++i) {
            int cnt = 1 + (i + 1 == board.size()? 0 : board[i+1]==board[i]);
            int idx = i;
            if(cnt >1) ++i;
            int need = 3 - cnt;
            if(hm[board[i]]< need) continue;
            hm[board[i]] -= need;
            string ns = board.substr(0, idx) + board.substr(idx+cnt);
            //cout<<"new string "<<ns<<endl;
            ns = merge(ns);
            //cout<<"after merge "<<ns<<endl;
            ans = min(ans, dfs(ns, hm) + need);
            hm[board[i]] += need;
        }
        return ans;
    }
};
```
      