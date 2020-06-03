//Link: https://leetcode.com/problems/largest-values-from-labels/ 
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, int> use;
        vector<pair<int, int> > vp;
        for(int i = 0; i < values.size(); ++i){
            vp.push_back({values[i], labels[i]});
        }
        sort(vp.begin(), vp.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.first > b.first;
        });
        int cnt = 0;
        int sum = 0;
        for(int i = 0; i < vp.size(); ++i){
            auto &p = vp[i];
            if(use[p.second] < use_limit){
                sum += p.first;
                ++use[p.second];
                ++cnt;
            }
            if(cnt >= num_wanted)
                return sum;
        }
        return sum;
    }
};