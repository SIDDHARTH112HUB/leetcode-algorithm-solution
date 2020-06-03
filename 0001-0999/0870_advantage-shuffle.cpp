//Link: https://leetcode.com/problems/advantage-shuffle/ 
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