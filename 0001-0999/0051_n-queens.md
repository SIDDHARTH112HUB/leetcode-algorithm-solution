[51.n-queens](https://leetcode.com/problems/n-queens/)  

The _n_\-queens puzzle is the problem of placing _n_ queens on an _n_×_n_ chessboard such that no two queens attack each other.

![](https://assets.leetcode.com/uploads/2018/10/12/8-queens.png)

Given an integer _n_, return all distinct solutions to the _n_\-queens puzzle.

Each solution contains a distinct board configuration of the _n_\-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space respectively.

**Example:**

  
**Input:** 4
  
**Output:** \[
  
 \[".Q..",  // Solution 1
  
  "...Q",
  
  "Q...",
  
  "..Q."\],
  

  
 \["..Q.",  // Solution 2
  
  "Q...",
  
  "...Q",
  
  ".Q.."\]
  
\]
  
**Explanation:** There exist two distinct solutions to the 4-queens puzzle as shown above.  



**Solution:**  

```cpp
class Solution {
public:
    bool check(vector<string> &board){
        //cout<<"begin "<<endl;
        for( int i = 0; i< board.size(); i++){
            int Q = 0;
            for( auto c:board[i]){
                if( c == 'Q')
                    Q++;
                if(Q > 1)
                    return false;
            }
            Q = 0;
            for( int j = 0; j<board.size(); j++){
                if( board[j][i] == 'Q')
                    Q++;
                if( Q > 1 )
                    return false;
            }
            Q = 0;
            int Q2 = 0;
            for(int j = 0; j<=i; j++){
                //cout<<i-j<<" "<<j<<" "<<endl;
                
                if( board[i-j][j] == 'Q' )
                    Q++;
                if( board[board.size()-1-i+j][board.size()-1-j] == 'Q' )
                    Q2++;
                if( Q > 1 || Q2>1 )
                    return false;
                    
            }
            //cout<<endl<<endl;
            Q = 0;
            Q2 = 0;
            for( int j = 0; j<=i; j++){
                //cout<<board.size()-1-i+j<<" "<<j<<" "<<endl;
                
                if( board[board.size()-1-i+j][j] == 'Q' )
                    Q++;
                if( board[j][board.size()-1-i+j] == 'Q' )
                    Q2++;
                if( Q > 1 || Q2>1 )
                    return false;
                    
            }
            //cout<<endl<<endl;
            
        }
        
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        //if( n == 1) return {{"Q"}};
        
        vector<vector<string> > ans;
        if( n <= 0) return ans;
        // write your code here
        //if( n <= 3 )    return ans;
        vector<string> board(n, string(n, '.') );
        
        dfs(board, 0, ans);
        return ans;
    }
    
    bool dfs(vector<string> &board, int idx, vector<vector<string> > &ans){
        int n = board.size();
        if( idx >= n ){
            ans.push_back(board);
            return true;
        }
        for( int i = 0; i<n; i++){
            board[idx][i] ='Q';
            if( check(board) == true){
                dfs(board, idx+1, ans);
            }
            board[idx][i] ='.';
        }
        return false;
    }
};
```
      