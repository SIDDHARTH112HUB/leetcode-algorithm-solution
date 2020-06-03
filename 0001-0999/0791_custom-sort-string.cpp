//Link: https://leetcode.com/problems/custom-sort-string/ 
class Solution {
public:
    string customSortString(string S, string T) {
        int hash[256] = {0};
        for(int i = 0; i < S.size(); i++)
            hash[S[i]] = i+1;
        sort(T.begin(), T.end(), [&hash](char a, char b){
            return hash[a] < hash[b];
        });
        return T;
    }
};