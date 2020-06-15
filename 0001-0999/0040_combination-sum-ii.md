[40.combination-sum-ii](https://leetcode.com/problems/combination-sum-ii/)  

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:**

*   All numbers (including `target`) will be positive integers.
*   The solution set must not contain duplicate combinations.

**Example 1:**

**Input:** candidates = `[10,1,2,7,6,1,5]`, target = `8`,
**A solution set is:**
\[
  \[1, 7\],
  \[1, 2, 5\],
  \[2, 6\],
  \[1, 1, 6\]
\]

**Example 2:**

**Input:** candidates = \[2,5,2,1,2\], target = 5,
**A solution set is:**
\[
  \[1,2,2\],
  \[5\]
\]  



**Solution:**  

```cpp
class Solution {
public:
    //vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    //}
    void combine( vector<int>& cand, int target,int idx,  vector<vector<int> >& ans, vector<int>& ans_item ){
        if( !target ){
            ans.push_back(ans_item);
            return;
        }
        if( target < 0 )
            return;
        if( idx >= cand.size() ) return;
        
        int upper = upper_bound (cand.begin(), cand.end(), cand[idx]) - cand.begin();
        //cout<<" upper "<<upper<<" idx:"<<idx<<endl;
        int same_size = upper-idx;
        //for( int i = idx; i<cand.size(); i++ ){
        for( int i = idx; i<=upper; i++ ){
            int t = target;
            for( int j = i; j<upper; j++ ){
                ans_item.push_back(cand[idx]);
                t -= cand[idx];
            }
            combine(cand, t, upper, ans, ans_item);
            for( int j = i; j<upper; j++ ){
                ans_item.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //cout<<"begin"<<endl;
        sort(candidates.begin(), candidates.end());
        //for( int i:candidates)
        //    cout<<i<<" "<<endl;
        cout<<endl;
        vector<vector<int> > ans;
        vector<int> ans_item;
        combine(candidates, target, 0, ans, ans_item);
        return ans;
    }
};
```
      