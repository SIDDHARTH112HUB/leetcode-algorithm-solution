//Link: https://leetcode.com/problems/palindrome-pairs/ 
class Solution {
public:
    bool isPalindrome(string &word){
        int l = 0, r = word.size()-1;
        while(l < r){
            if( word[l] != word[r])return false;
            l++;
            r--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        unordered_map<char, map<string, int> > dict;
        unordered_set<int> parlindrome;
        for( int i = 0; i<words.size(); i++){
            string &str = words[i];
            if( str.size() > 0 )
                dict[str.back()][str] = i;
            else{
                for( char a = 'a'; a<='z'; a++){
                    dict[a][str] = i;
                }
            }
            if( isPalindrome(str) ){
                parlindrome.insert(i);
            }
        }
        for( int i = 0; i<words.size(); i++){
            string word = words[i];
            if( word.size() == 0 ){
                for( auto num: parlindrome){
                    if( num == i || ( i> num && words[num] == words[i]))
                        continue;
                    ans.push_back({i, num});
                }
                continue;
            }
            for(auto &it: dict[word[0]]){
                if( it.second == i )continue;
                string str = word + it.first;
                if( isPalindrome(str)){
                    ans.push_back({i, it.second});
                }
            }
        }
        return ans;
    }
};