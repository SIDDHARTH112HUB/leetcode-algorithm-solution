[433.minimum-genetic-mutation](https://leetcode.com/problems/minimum-genetic-mutation/)  

A gene string can be represented by an 8-character long string, with choices from `"A"`, `"C"`, `"G"`, `"T"`.

Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.

For example, `"AACCGGTT"` -> `"AACCGGTA"` is 1 mutation.

Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.

Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.

**Note:**

1.  Starting point is assumed to be valid, so it might not be included in the bank.
2.  If multiple mutations are needed, all mutations during in the sequence must be valid.
3.  You may assume start and end string is not the same.

**Example 1:**

start: "AACCGGTT"
end:   "AACCGGTA"
bank: \["AACCGGTA"\]

return: 1

**Example 2:**

start: "AACCGGTT"
end:   "AAACGGTA"
bank: \["AACCGGTA", "AACCGCTA", "AAACGGTA"\]

return: 2

**Example 3:**

start: "AAAAACCC"
end:   "AACCCCCC"
bank: \["AAAACCCC", "AAACCCCC", "AACCCCCC"\]

return: 3  



**Solution:**  

```cpp
class Solution {
public:
    int diff_count( string &a, string &b){
        int cnt = 0;
        for( int i = 0; i<a.size(); i++){
            if( a[i] != b[i])
                cnt++;
        }
        return cnt;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        if( bank.size() == 0 ) return -1;
        bank.push_back(start);
        int n = bank.size();
        vector<vector<int> > dist(n, vector<int>(n, 0));

        for( int i = 0; i < bank.size(); i++){
            for( int j = i+1; j<bank.size(); j++){
                dist[i][j] = diff_count(bank[i], bank[j]);
            }
        }
        unordered_set<int> visited;
        queue<int> q;
        q.push( n - 1);
        int ans = 0;
        while( q.size() ){
            int len = q.size();
            ++ans;
            for( int i = 0; i<len; i++){
                int t = q.front();q.pop();
                visited.insert(t);
                for( int j = 0; j<n; j++ ){
                    if( ( dist[j][t] != 1 && dist[t][j]!=1 )  || visited.count(j) != 0 ) continue;
                    if( bank[j] == end ) return ans;
                    q.push(j);
                }
            }
        }
        return -1;
        
    }
};
```
      