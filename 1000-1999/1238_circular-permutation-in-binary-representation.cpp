//Link: https://leetcode.com/problems/circular-permutation-in-binary-representation/ 
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> arr;
        arr.push_back(0);
        arr.push_back(1);
        for(int i = 1; i <n; ++i) {
            int size = arr.size();
            int num = 1 << i;
            for(int j = size - 1; j>=0; --j) {
                arr.push_back(num + arr[j]);
            }
        }
        vector<int> ans;
        int idx = -1;
        for(int i = 0; i <arr.size(); ++i) {
            if(arr[i] == start) {
                if(idx == -1)
                    idx = i;
            }
            if(idx >= 0) {
                ans.push_back(arr[i]);
            }
        }
        
        for(int i = 0; i < idx; ++i)
            ans.push_back(arr[i]);
        return ans;
    }
};