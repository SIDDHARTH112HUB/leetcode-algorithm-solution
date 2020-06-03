//Link: https://leetcode.com/problems/minimum-window-substring/ 
class Solution {
public:
    string minWindow(string s, string t) {
        int end = 0, begin = 0, counter = 0, size = s.size();
        unordered_map<int, int> hash;
        pair<int, int> ans = {0, 100000000};
        for( char c :t) ++hash[c];
        counter = hash.size();
        while(end < size ) {
            if( hash[s[end++]]-- == 1 ) counter--;
            while(counter == 0 &&  begin < end ){
                if( end - begin < ans.second - ans.first ) ans={begin, end};
                if(hash[s[begin++]]++ >= 0) counter++;
            }
        }
        return ans.second-ans.first>size ? "" : s.substr(ans.first, ans.second-ans.first);
    }
};