[957.prison-cells-after-n-days](https://leetcode.com/problems/prison-cells-after-n-days/)  

There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

*   If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
*   Otherwise, it becomes vacant.

(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: `cells[i] == 1` if the `i`\-th cell is occupied, else `cells[i] == 0`.

Given the initial state of the prison, return the state of the prison after `N` days (and `N` such changes described above.)

**Example 1:**

**Input:** cells = \[0,1,0,1,1,0,0,1\], N = 7
**Output:** \[0,0,1,1,0,0,0,0\]
**Explanation:** The following table summarizes the state of the prison on each day:
Day 0: \[0, 1, 0, 1, 1, 0, 0, 1\]
Day 1: \[0, 1, 1, 0, 0, 0, 0, 0\]
Day 2: \[0, 0, 0, 0, 1, 1, 1, 0\]
Day 3: \[0, 1, 1, 0, 0, 1, 0, 0\]
Day 4: \[0, 0, 0, 0, 0, 1, 0, 0\]
Day 5: \[0, 1, 1, 1, 0, 1, 0, 0\]
Day 6: \[0, 0, 1, 0, 1, 1, 0, 0\]
Day 7: \[0, 0, 1, 1, 0, 0, 0, 0\]

**Example 2:**

**Input:** cells = \[1,0,0,1,0,0,1,0\], N = 1000000000
**Output:** \[0,0,1,1,1,1,1,0\]

**Note:**

1.  `cells.length == 8`
2.  `cells[i]` is in `{0, 1}`
3.  `1 <= N <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    string cellFormat(vector<int> &cells){
        string ans;
        for( int cell: cells)
            ans += '0' + cell;
        return ans;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map< string, int > m;
        string cellStr = cellFormat( cells ), prev;
        vector<int> ans;
        while( m.count(cellStr) == 0 ){
            if( m.size() == N ){
                for( auto c : cellStr)
                    ans.push_back(c-'0');
                return ans;
            }
            prev = cellStr;
            m[cellStr] = m.size();
            string nc = cellStr;
            nc[0] = '0';
            nc[7] = '0';
            for( int i = 1; i < 7; i++){
                nc[i] = (cellStr[i-1] == cellStr[i+1]) ? '1':'0';
            }
            cellStr = nc;
        }
        
        int day = (N - m.size()) % (m[prev] - m[cellStr]+1);
        for( auto it: m){
            if( it.second - m[cellStr] == day){
                for( auto c: it.first)
                    ans.push_back(c-'0');
                return ans;
            }
        }
        return {};
    }
};

```
      