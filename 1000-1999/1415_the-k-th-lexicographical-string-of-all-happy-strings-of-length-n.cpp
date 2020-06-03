//Link: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/ 
class Solution {
public:
    string ans;
    string getHappyString(int n, int k) {
        string s;
        h(s, n, k);
        return ans;
    }
    
    bool h(string &s, int n, int &k) {
        
        if(s.size() >= n) {
            --k;
            if(k == 0){
                ans = s;
                return true;
            }
            return false;
        }
        for(int i = 'a'; i <= 'c'; ++i) {
            if(s.size() == 0 || s.back() != i) {
                s += i;
                if(h(s, n, k))
                    return true;
                s.pop_back();
            }
        }
        return false;
    }
};