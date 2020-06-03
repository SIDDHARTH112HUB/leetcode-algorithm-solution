//Link: https://leetcode.com/problems/guess-the-word/ 
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int h(string &a, string &b) {
        int ans = 0;
        for(int i = 0; i < a.size(); ++i) 
            if(a[i] == b[i])
                ++ans;
        return ans;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int idx = rand() % wordlist.size();
        string &str = wordlist[idx];
        int s = master.guess(str);
        if(s == str.size()) return;
        vector<string> nl;
        for(int i = 0; i < wordlist.size(); ++i ){
            if(i == idx) continue;
            if( s == h(wordlist[i], wordlist[idx]))
                nl.push_back(wordlist[i]);
        }
        return findSecretWord(nl, master);
    }
};