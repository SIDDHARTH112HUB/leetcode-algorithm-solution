//Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/ 
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> m;
        for(auto n : arr) {
            ++m[n];
        }
        vector<pair<int, int> > cnt;
        for(auto it : m) {
            cnt.push_back({it.second, it.first});
        }
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < cnt.size(); ++i) {
            if(k >= cnt[i].first) {
                k -= cnt[i].first;
            }else {
                return cnt.size() - i;
            }
        }
        return 0;
    }
};