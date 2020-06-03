//Link: https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/ 
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sum = 0, ans = 0;
        for(auto n : arr) {
            if(sum + n <= 5000)
                ++ans;
            else
                break;
            sum += n;
        }
        return ans;
    }
};