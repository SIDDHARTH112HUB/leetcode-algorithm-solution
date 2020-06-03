//Link: https://leetcode.com/problems/max-chunks-to-make-sorted/ 
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int first = arr[0];
        int i = 1;
        int ans = 1;
        while(i<arr.size()){
            if(arr[i]>first){
                if(i>first)
                    ans++;
                first =arr[i];
            }
            
            i++;
        }
        return ans;
    }
};