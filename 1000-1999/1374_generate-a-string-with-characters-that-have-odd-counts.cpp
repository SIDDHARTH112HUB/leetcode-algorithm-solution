//Link: https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/ 
class Solution {
public:
    string generateTheString(int n) {
        string a(n, 'a');
        a.back() = n % 2 ? 'a' : 'b';
        return a;
    }
};