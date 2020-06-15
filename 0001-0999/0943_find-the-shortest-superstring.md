[943.find-the-shortest-superstring](https://leetcode.com/problems/find-the-shortest-superstring/)  

Given an array A of strings, find any smallest string that contains each string in `A` as a substring.

We may assume that no string in `A` is substring of another string in `A`.

**Example 1:**

**Input:** \["alex","loves","leetcode"\]
**Output:** "alexlovesleetcode"
**Explanation:** All permutations of "alex","loves","leetcode" would also be accepted.

**Example 2:**

**Input:** \["catg","ctaagt","gcta","ttca","atgcatc"\]
**Output:** "gctaagttcatgcatc"

**Note:**

1.  `1 <= A.length <= 12`
2.  `1 <= A[i].length <= 20`  



**Solution:**  

```cpp
//["vgrikrnwezryimj","umwgwvzpsfpmctzt","pjourlpgeemdjor","urlpgeemdjorpzbkbz","jorpzbkbzcqyewih","xuwkzvoczozhhvf","ihbumoogibirbsvch","nwezryimjivvpjourlp","kzvoczozhhvfwgeplv","ezryimjivvpjourlpgee","zhhvfwgeplvqngglu","rikrnwezryimjivvp"]
class Solution {
public:
    int g[12][12]={0};
    int best_len = INT_MAX;
    vector<int> best_path;
    string shortestSuperstring(vector<string>& A) {
        for( int i = 0; i<A.size(); i++ ){
            for( int j = 0; j<A.size(); j++ ){
                if( i == j ) continue;
                string &a = A[i], &b=A[j];
                g[i][j] = b.size();
                for( int k = 1; k<= min(a.size(), b.size()); k++){
                    if( a.substr(a.size()-k) == b.substr(0, k ) ) {
                        g[i][j] = b.size()-k;
                    }
                }
            }
        }
        vector<int> path(A.size());
        dfs( A, 0, 0,0, path);
        string ans;
        for( int i = 0; i<best_path.size(); i++ ){
            int idx = best_path[i];
            ans += i == 0 ? A[idx]: A[idx].substr( A[idx].size()- g[best_path[i-1]][idx]);
        }
        return ans;
    }
    void dfs(vector<string>& A, int used, int idx, int cur_len, vector<int> &path){
        if( cur_len > best_len )
            return;
        if( idx >= A.size() ){
            if( cur_len < best_len ){
                best_len = cur_len;
                best_path = path;
            }
            return;
        }
        for( int i = 0; i<A.size(); i++){
            if( used & (1<<i) )continue;
            path[idx] = i;
            int size = A[i].size();
            dfs(A, used | (1<<i), idx+1, cur_len + (idx == 0?size:g[path[idx-1]][i]), path);
        }
    }
};
```
      