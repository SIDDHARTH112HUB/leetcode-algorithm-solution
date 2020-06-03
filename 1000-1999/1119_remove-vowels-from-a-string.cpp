//Link: https://leetcode.com/problems/remove-vowels-from-a-string/ 
class Solution {
public:
    string removeVowels(string S) {
        string ans;
        
        for(auto c : S){
            if(c != 'a' && c != 'e'&& c !='i' && c != 'o' && c != 'u')
                ans += c;
        }
        return ans;
    }
};