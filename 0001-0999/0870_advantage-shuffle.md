[870.advantage-shuffle](https://leetcode.com/problems/advantage-shuffle/)  

Given two arrays `A` and `B` of equal size, the _advantage of `A` with respect to `B`_ is the number of indices `i` for which `A[i] > B[i]`.

Return **any** permutation of `A` that maximizes its advantage with respect to `B`.

**Example 1:**

  
**Input:** A = \[2,7,11,15\], B = \[1,10,4,11\]
  
**Output:** \[2,11,7,15\]
  

**Example 2:**

  
**Input:** A = \[12,24,8,32\], B = \[13,25,32,11\]
  
**Output:** \[24,32,8,12\]
  

**Note:**

1.  `1 <= A.length = B.length <= 10000`
2.  `0 <= A[i] <= 10^9`
3.  `0 <= B[i] <= 10^9`  



**Solution:**  

```cpp
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<pair<int, int> > BP;
        for( int i = 0; i<B.size(); i++){
            BP.push_back({B[i], i});
        }
        vector<int> ans(A.size());
        sort(BP.begin(), BP.end());
        int i = 0, j = 0;
        vector<int> remain;
        while( i<A.size() && j < BP.size()){
            if( A[i] > BP[j].first){
                ans[BP[j].second] = A[i];
                j++;
            }else
                remain.push_back(A[i]);
            i++;
        }
        while( remain.size() ){
            ans[BP[j++].second] = remain.back();
            remain.pop_back();
        }
        return ans;
    }
};
```
      