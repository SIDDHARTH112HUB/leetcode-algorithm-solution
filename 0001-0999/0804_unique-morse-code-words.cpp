//Link: https://leetcode.com/problems/unique-morse-code-words/ 
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26]= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string, int> data;
        for( auto &word: words){
            string a;
            for( auto c: word){
                a += morse[c-'a'];
            }
            data[a] += 1;
        }
        return data.size();
    }
};