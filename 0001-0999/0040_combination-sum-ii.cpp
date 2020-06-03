//Link: https://leetcode.com/problems/combination-sum-ii/ 
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