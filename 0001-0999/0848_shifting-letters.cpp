//Link: https://leetcode.com/problems/shifting-letters/ 
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        for( int i = shifts.size()-2; i>=0; i--){
            shifts[i] = (shifts[i]+shifts[i+1])%26;
        }
        for( int i = 0; i<S.size(); i++){
            S[i] = ((S[i] + shifts[i])-'a')%26+'a';
        }
        return S;
    }
};