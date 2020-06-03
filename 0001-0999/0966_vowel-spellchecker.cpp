//Link: https://leetcode.com/problems/vowel-spellchecker/ 

unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
class Solution {
public:
    string toLower(string str){
        for( char &c:str){
            if( c >= 'A' && c <= 'Z' )
                c += 'a' - 'A';
        }
        return str;
    }
    string toVowel(string str){
        for( char &c:str){
            if( vowels.count(c) ){
                c = '#';
            }
        }
        return str;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> lowerMap;
        unordered_set<string> m;
        vector<string> ans;
        for(string &word : wordlist){
            m.insert(word);
            auto lower = toLower(word);
            if( lowerMap.count(lower) == 0 )
                lowerMap[lower] = word;
            auto v = toVowel(lower);
            if( lowerMap.count(v) == 0 )
                lowerMap[v] = word;
        }
        for( string &query : queries){
            if( m.count(query)){
                ans.push_back(query);
                continue;
            }
            auto lower = toLower(query);
            if( lowerMap.count(lower) ){
                ans.push_back(lowerMap[lower]);
                continue;
            }
            auto vowel = toVowel(lower);
            if( lowerMap.count(vowel) ){
                ans.push_back(lowerMap[vowel]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};