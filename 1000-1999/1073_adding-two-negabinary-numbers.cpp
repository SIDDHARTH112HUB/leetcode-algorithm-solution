//Link: https://leetcode.com/problems/adding-two-negabinary-numbers/ 
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        vector<int> res;
        int c = 0, i = 0, j = 0, d = 0;
        while( i < arr1.size() || j < arr2.size() || c != 0 || d != 0) {
            int a = i < arr1.size() ? arr1[i] : 0;
            int b = j < arr2.size() ? arr2[j] : 0;
            int s = (a + b) * (i % 2 ? -1 : 1) + c + d;
            res.push_back(abs(s%2));
            if(s % 2 != (i % 2 ? -1 : 1))
                d = (s % 2);
            else 
                d = 0;
            c = s / 2;
            ++j, ++i;
        }
        if(res.size() == 0) return {0};
        while(res.size() > 1 && res.back() == 0)
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};