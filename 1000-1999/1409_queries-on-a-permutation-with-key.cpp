//Link: https://leetcode.com/problems/queries-on-a-permutation-with-key/ 
class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int t) {
        vector<int> arr, ans;
        for(int i = 1; i <=t; ++i)
            arr.push_back(i);
        for(auto q : queries) {
            int i = 0;
            for(; i < arr.size(); ++i) {
                if(q == arr[i]) {
                    ans.push_back(i);break;
                }
            }
            int num = arr[i];
            arr.erase(arr.begin() + i);
            arr.insert(arr.begin(), num);
        }
        return ans;
    }
};