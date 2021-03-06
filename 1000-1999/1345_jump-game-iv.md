[1345.jump-game-iv](https://leetcode.com/problems/jump-game-iv/)  

Given an array of integers `arr`, you are initially positioned at the first index of the array.

In one step you can jump from index `i` to index:

*   `i + 1` where: `i + 1 < arr.length`.
*   `i - 1` where: `i - 1 >= 0`.
*   `j` where: `arr[i] == arr[j]` and `i != j`.

Return _the minimum number of steps_ to reach the **last index** of the array.

Notice that you can not jump outside of the array at any time.

**Example 1:**

  
**Input:** arr = \[100,-23,-23,404,100,23,23,23,3,404\]
  
**Output:** 3
  
**Explanation:** You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
  

**Example 2:**

  
**Input:** arr = \[7\]
  
**Output:** 0
  
**Explanation:** Start index is the last index. You don't need to jump.
  

**Example 3:**

  
**Input:** arr = \[7,6,9,6,9,6,9,7\]
  
**Output:** 1
  
**Explanation:** You can jump directly from index 0 to index 7 which is last index of the array.
  

**Example 4:**

  
**Input:** arr = \[6,1,9\]
  
**Output:** 2
  

**Example 5:**

  
**Input:** arr = \[11,22,7,7,7,7,7,7,7,22,13\]
  
**Output:** 3
  

**Constraints:**

*   `1 <= arr.length <= 5 * 10^4`
*   `-10^8 <= arr[i] <= 10^8`  



**Solution:**  

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int> > m;
        for(int i = arr.size() - 1; i >=0; --i) {
            m[arr[i]].push_back(i);
        }
        queue<int> q;q.push(0);
        unordered_set<int> v;v.insert(0);
        int step = 0;
        while(q.size()) {
            int size = q.size();
            while(size-->0) {
                int cur = q.front();q.pop();
                if(cur == arr.size()-1) return step;
                for(auto n : m[arr[cur]]) {
                    if(v.count(n)) continue;
                    if(n == arr.size()-1) return step+1;
                    v.insert(n);
                    q.push(n);
                }
                for(int i = 1; i >= -1; i-=2) {
                    int nx = cur + i;
                    if(nx <0 || nx >= arr.size()) continue;
                    if(v.count(nx)) continue;
                    if(nx == arr.size() -1) return step + 1;
                    v.insert(nx);
                    q.push(nx);
                }
            }
            ++step;
        }
        return -1;
    }
};
```
      