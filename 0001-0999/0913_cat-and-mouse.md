[913.cat-and-mouse](https://leetcode.com/problems/cat-and-mouse/)  

A game on an **undirected** graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: `graph[a]` is a list of all nodes `b` such that `ab` is an edge of the graph.

Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.

During each player's turn, they **must** travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node `1`, it **must** travel to any node in `graph[1]`.

Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)

Then, the game can end in 3 ways:

*   If ever the Cat occupies the same node as the Mouse, the Cat wins.
*   If ever the Mouse reaches the Hole, the Mouse wins.
*   If ever a position is repeated (ie. the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.

Given a `graph`, and assuming both players play optimally, return `1` if the game is won by Mouse, `2` if the game is won by Cat, and `0` if the game is a draw.

**Example 1:**

  
**Input:** \[\[2,5\],\[3\],\[0,4,5\],\[1,4,5\],\[2,3\],\[0,2,3\]\]
  
**Output:** 0
  
**Explanation:** 4---3---1
  
|   |
  
2---5
  
 \\ /
  
  0
  

**Note:**

1.  `3 <= graph.length <= 50`
2.  It is guaranteed that `graph[1]` is non-empty.
3.  It is guaranteed that `graph[2]` contains a non-zero element.  



**Solution:**  

```cpp
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(2 * n, vector<vector<int>>(n, vector<int>(n, -1)));
        return helper(graph, 0, 1, 2, dp);
    }
    int helper(vector<vector<int>>& graph, int t, int x, int y, vector<vector<vector<int>>>& dp) {
        if (t == graph.size() * 2) return 0;
        if (x == y) return dp[t][x][y] = 2;
        if (x == 0) return dp[t][x][y] = 1;
        if (dp[t][x][y] != -1) return dp[t][x][y];
        bool mouseTurn = (t % 2 == 0);
        if (mouseTurn) {
            bool catWin = true;
            for (int i = 0; i < graph[x].size(); ++i) {
                int next = helper(graph, t + 1, graph[x][i], y, dp);
                if (next == 1) return dp[t][x][y] = 1;
                else if (next != 2) catWin = false;
            }
            if (catWin) return dp[t][x][y] = 2;
            else return dp[t][x][y] = 0;
        } else {
            bool mouseWin = true;
            for (int i = 0; i < graph[y].size(); ++i) {
                if (graph[y][i] == 0) continue;
                int next = helper(graph, t + 1, x, graph[y][i], dp);
                if (next == 2) return dp[t][x][y] = 2;
                else if (next != 1) mouseWin = false;
            }
            if (mouseWin) return dp[t][x][y] = 1;
            else return dp[t][x][y] = 0;
        }
    }
};
```
      