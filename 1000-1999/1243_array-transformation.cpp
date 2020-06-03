//Link: https://leetcode.com/problems/array-transformation/ 
class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        vector<int> ans(arr.size());
        ans = arr;
        bool f=true;
        ans[0] = arr[0];
        ans[ans.size()-1] = arr[arr.size()-1];
        while(f){
            f = false;
        for(int i = 1;i<arr.size()-1;i++){
            
            if(arr[i-1] > arr[i] && arr[i+1]>arr[i]){
                f= true;
                ans[i]=arr[i]+1;
            }
            if(arr[i-1]<arr[i] && arr[i+1] < arr[i]){
                f=true;
                ans[i] = arr[i]- 1;
            }
            
        }
            arr = ans;
        }
        //ans[ans.size()-1] = arr[ans.size() - 1];
        return ans;
    }
};