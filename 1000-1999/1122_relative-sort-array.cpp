//Link: https://leetcode.com/problems/relative-sort-array/ 
class Solution {
public:
    unordered_map<int, int> m;
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        for(int i = 0; i < arr1.size(); ++i){
            int n = arr1[i];
            m[n] = 10000 + n;
            }
        for(int i = 0; i < arr2.size(); ++i){
            int n = arr2[i];
            m[n] = i + 1;
        }
        sort(arr1.begin(), arr1.end(), [this](int n1, int n2){
            return m[n1] < m[n2];
        });
        return arr1;
    }
};