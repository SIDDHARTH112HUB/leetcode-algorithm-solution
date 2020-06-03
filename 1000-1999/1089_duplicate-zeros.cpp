//Link: https://leetcode.com/problems/duplicate-zeros/ 
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> a1;
        for(auto n : arr){
            a1.push_back(n);
            if(n == 0)
                a1.push_back(n);
        }
        for(int i = 0; i < arr.size(); ++i){
            arr[i] = a1[i];
        }
    }
};