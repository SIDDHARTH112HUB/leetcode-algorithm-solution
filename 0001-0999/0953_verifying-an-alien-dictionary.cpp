//Link: https://leetcode.com/problems/verifying-an-alien-dictionary/ 
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char hash[128] = {0};
        for( int i = 0; i< order.size(); i++ ){
            hash[order[i]] = 'a' + i;
        }
        auto origin = words;
        sort(words.begin(), words.end(), [hash](string &a, string &b){
            
            string a1, b1;
            for( auto c : a)
                a1 += hash[c];
            for( auto c : b)
                b1 += hash[c];
            return a1 < b1;
        });
        for( int i = 0; i<origin.size(); i++)
            if( origin[i] != words[i])
                return false;
        return true;
    }
};