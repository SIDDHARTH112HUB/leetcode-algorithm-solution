[996.number-of-squareful-arrays](https://leetcode.com/problems/number-of-squareful-arrays/)  

Given an array `A` of non-negative integers, the array is _squareful_ if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of A that are squareful.  Two permutations `A1` and `A2` differ if and only if there is some index `i` such that `A1[i] != A2[i]`.

**Example 1:**

**Input:** \[1,17,8\]
**Output:** 2
**Explanation:** 
\[1,8,17\] and \[17,8,1\] are the valid permutations.

**Example 2:**

**Input:** \[2,2,2\]
**Output:** 1

**Note:**

1.  `1 <= A.length <= 12`
2.  `0 <= A[i] <= 1e9`  



**Solution:**  

```cpp
class Solution {
public:
    bool check( vector<int>& A ){
        for( int i = 0; i< A.size() - 1; i++ ){
            int sq = sqrt(A[i] + A[i+1]);
            if( sq * sq != A[i] + A[i+1])
                return false;
        }
        return true;
    }
    int ans = 0; 
    unordered_map<int, int> count;
    unordered_map<int, unordered_set<int> > sq;
    int numSquarefulPerms(vector<int>& A) {
        for( auto a : A){
            ++count[a];
        }
        for( auto &i : count ){
            for( auto &j : count){
                int x = i.first, y = j.first, s = sqrt(x+y);
                if( s * s == x + y )
                    sq[x].insert(y);
            }   
        }
        for( auto &it : count )
            solve(it.first, A.size()-1);
        return ans;
    }
    
    void solve(int x, int left){
        --count[x];
        if( !left ) ++ans;
        else{
            for( auto y : sq[x]){
                if( count[y] > 0 )
                    solve(y, left-1);
            }
        }
        ++count[x];
    }
};
```
      