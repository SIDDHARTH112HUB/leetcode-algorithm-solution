//Link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/ 
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<int, int> h;
        for(auto c : chars)
            ++h[c];
        int ans = 0;
        for(auto &word : words ){
            auto t = h;
            ans += word.size();
            for(auto c : word){
                if(--t[c] < 0){
                    ans -= word.size();
                    break;
                }       
            }
        }
        return ans;
    }
};
