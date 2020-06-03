//Link: https://leetcode.com/problems/sum-of-digits-in-the-minimum-number/ 
class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int mn = *min_element(A.begin(), A.end());
        int sum = 0;
        while(mn > 0){
            sum += mn % 10;
            mn /= 10;
        }
        return sum % 2 == 0;
    }
};