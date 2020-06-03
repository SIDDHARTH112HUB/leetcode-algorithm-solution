//Link: https://leetcode.com/problems/permutation-sequence/ 
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> f = vector<int>(n, 1);
        string num = "123456789";
        string ans = "";
        
        for( int i = 1; i<n; i++) f[i] = f[i-1]*i;
        --k;
        for( int i =n-1; i>=0; i--){
            int digit = k/f[i];
            k = k%f[i];
            ans.push_back(num[digit]);
            num.erase(digit,1);
        }
        return ans;
    }
};