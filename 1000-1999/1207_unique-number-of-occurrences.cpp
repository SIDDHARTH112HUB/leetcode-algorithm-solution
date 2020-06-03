//Link: https://leetcode.com/problems/unique-number-of-occurrences/ 
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> cnt;
        for(auto n : arr)
            ++cnt[n];
        map<int, int> u;
        for(auto it : cnt) {
            if(u[it.second] > 0)
                return false;
            ++u[it.second];
        }
        return true;
    }
};