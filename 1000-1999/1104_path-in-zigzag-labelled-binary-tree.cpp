//Link: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/ 
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        while(label>0){
            ans.push_back(label);
            label /= 2;
            if(label == 0)
                break;
            int p = 0;
            while(pow(2, p) <= label)++p;
            label = pow(2, p ) -1 - (label- pow(2, p-1));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};