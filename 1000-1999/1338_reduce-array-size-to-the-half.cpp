//Link: https://leetcode.com/problems/reduce-array-size-to-the-half/ 
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        for(auto n : arr)
            ++m[n];
        vector<pair<int,int> > a;
        for(auto &it: m) {
            a.push_back({it.second, it.first});
        }
        sort(a.begin(), a.end());
        int sum = 0, ans = 0;
        for(int i = a.size()-1; i >=0; --i){
            if(sum + a[i].first >= (arr.size()+1)/2)
                return ans + 1;
            sum += a[i].first;
            ++ans;
        }
        return a.size();
    }
};