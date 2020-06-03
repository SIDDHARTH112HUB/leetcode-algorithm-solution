//Link: https://leetcode.com/problems/n-th-tribonacci-number/ 
class Solution {
public:
    int tribonacci(int n) {
        vector<long long> a(100);
        a[0] = 0;
        a[1] = 1;
        a[2] = 1;
        for(int i = 3; i < n+3; ++i){
            a[i] = a[i-2] + a[i-1] + a[i-3];
        }
        return a[n];
    }
};