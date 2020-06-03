//Link: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/ 
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx = arr.back();
        arr[arr.size()-1] = -1;
        for(int i = arr.size()-2; i >=0; --i) {
            int src = arr[i];
            arr[i] = mx;
            mx = max(src, mx);
        }
        return arr;
    }
};