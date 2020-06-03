//Link: https://leetcode.com/problems/palindrome-permutation/ 
class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<int,int> m;
        for(auto c : s) ++m[c];
        int odd = 0;
        for(auto it : m)
            odd += it.second % 2;
        return odd <= 1;
    }
};