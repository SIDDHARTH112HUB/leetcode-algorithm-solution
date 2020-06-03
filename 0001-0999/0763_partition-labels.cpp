//Link: https://leetcode.com/problems/partition-labels/ 
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int right[128] = {0};
        for(int i = S.size() - 1; i >= 0; --i) {
            if(right[S[i]] == 0)
                right[S[i]] = i;
        }
        vector<int> ans;
        int mxRight = 0, prev = -1;
        for(int i = 0; i < S.size(); ++i) {
            mxRight = max(mxRight, right[S[i]]);
            if(mxRight == i) {
                ans.push_back(i - prev);
                prev = i;
                mxRight = 0;
            }
        }
        return ans;
    }
};