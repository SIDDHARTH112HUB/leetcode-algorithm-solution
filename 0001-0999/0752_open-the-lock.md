[752.open-the-lock](https://leetcode.com/problems/open-the-lock/)  

You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: `'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'`. The wheels can rotate freely and wrap around: for example we can turn `'9'` to be `'0'`, or `'0'` to be `'9'`. Each move consists of turning one wheel one slot.

The lock initially starts at `'0000'`, a string representing the state of the 4 wheels.

You are given a list of `deadends` dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a `target` representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

**Example 1:**  

  
**Input:** deadends = \["0201","0101","0102","1212","2002"\], target = "0202"
  
**Output:** 6
  
**Explanation:**
  
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
  
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
  
because the wheels of the lock become stuck after the display becomes the dead end "0102".
  

**Example 2:**  

  
**Input:** deadends = \["8888"\], target = "0009"
  
**Output:** 1
  
**Explanation:**
  
We can turn the last wheel in reverse to move from "0000" -> "0009".
  

**Example 3:**  

  
**Input:** deadends = \["8887","8889","8878","8898","8788","8988","7888","9888"\], target = "8888"
  
**Output:** -1
  
**Explanation:**
  
We can't reach the target without getting stuck.
  

**Example 4:**  

  
**Input:** deadends = \["0000"\], target = "8888"
  
**Output:** -1
  

**Note:**  

1.  The length of `deadends` will be in the range `[1, 500]`.
2.  `target` will not be in the list `deadends`.
3.  Every string in `deadends` and the string `target` will be a string of 4 digits from the 10,000 possibilities `'0000'` to `'9999'`.  



**Solution:**  

```cpp
class Solution {
public:
    unordered_set<string> visited;
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadset(deadends.begin(), deadends.end());
        string start = "0000";
        if( start == target ) return 0;
        if( deadset.count(start) ) return -1;
        unordered_set<string> visited = {start};
        queue<string> q;
        q.push(start);
        int ans = 0;
        while(q.size()){
            int size = q.size();
            ans++;
            while(size-->0){
                string str = q.front();
                
                for( auto &c:str){
                    char src = c;
                    for( int i = -1; i<=1; i+=2){
                        c = ((c + i + 10-'0')%10) + '0';
                        if( str == target )
                            return ans;
                        if( !visited.count(str) && !deadset.count(str) ) {
                            q.push(str);
                            visited.insert(str);
                        }
                        c = src;
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};
```
      