[444.sequence-reconstruction](https://leetcode.com/problems/sequence-reconstruction/)  

Check whether the original sequence `org` can be uniquely reconstructed from the sequences in `seqs`. The `org` sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. Reconstruction means building a shortest common supersequence of the sequences in `seqs` (i.e., a shortest sequence so that all sequences in `seqs` are subsequences of it). Determine whether there is only one sequence that can be reconstructed from `seqs` and it is the `org` sequence.

**Example 1:**

  
**Input:** org = \[1,2,3\], seqs = \[\[1,2\],\[1,3\]\]  
**Output:** false  
**Explanation:** \[1,2,3\] is not the only one sequence that can be reconstructed, because \[1,3,2\] is also a valid sequence that can be reconstructed.  

**Example 2:**

  
**Input:** org = \[1,2,3\], seqs = \[\[1,2\]\]  
**Output:** false  
**Explanation:** The reconstructed sequence can only be \[1,2\].  

**Example 3:**

  
**Input:** org = \[1,2,3\], seqs = \[\[1,2\],\[1,3\],\[2,3\]\]  
**Output:** true  
**Explanation:** The sequences \[1,2\], \[1,3\], and \[2,3\] can uniquely reconstruct the original sequence \[1,2,3\].  

**Example 4:**

  
**Input:** org = \[4,1,5,2,6,3\], seqs = \[\[5,2,6,3\],\[4,1,5,2\]\]  
**Output:** true  

**Constraints:**

*   `1 <= n <= 10^4`
*   `org` is a permutation of {1,2,...,n}.
*   `seqs[i][j]` fits in a 32-bit signed integer.

**UPDATE (2017/1/8):**  
The _seqs_ parameter had been changed to a list of list of strings (instead of a 2d array of strings). Please reload the code definition to get the latest changes.  



**Solution:**  

```cpp
class Solution {
public:
    map<int, set<int> > g;
    int ans = 0;
    set<int> v;
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if(seqs.size() == 0) return false;
        int n = org.size();
        vector<int> indegree(org.size() + 1, -1);
        for(auto &seq : seqs) {
            if(seq.size() == 0) continue;
            if(seq[0] > n || seq[0] <= 0) return false;
            g[seq[0]];
            if(indegree[seq[0]] == -1)
                indegree[seq[0]] = 0;
            for(int i = 1; i < seq.size(); ++i) {
                if(seq[i] > n || seq[i] <= 0) return false;
                g[seq[i-1]].insert(seq[i]);
                if(indegree[seq[i]] == -1)
                    indegree[seq[i]] = 0;
                ++indegree[seq[i]];
            }
        }
        for(int i = 1; i < indegree.size(); ++i) {
            if(indegree[i] == 0) {
                if(isCircle(i)) return false;
                v = {};
            }
        }
        
        for(int i = 1; i < indegree.size(); ++i) {
            if(indegree[i] == 0 && dfs(i, org, 0))
                return true;
        }
        return false;
    }
    bool isCircle(int num) {
        if(v.count(num)) return true;
        v.insert(num);
        for(auto next : g[num]) {
            if(isCircle(next)) return true;
        }
        v.erase(num);
        return false;
    }
    bool dfs(int num, vector<int> &org, int idx) {
        if(idx + 1 == org.size()) return true;
        if(org[idx] != num) return false;
        for(auto next : g[num]) {
            if(dfs(next, org, idx + 1)) return true;
        }
        return false;
    }
};
```
      