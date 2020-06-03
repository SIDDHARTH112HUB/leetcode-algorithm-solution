//Link: https://leetcode.com/problems/sort-characters-by-frequency/ 
class Solution {
public:
    string frequencySort(string s) {
        
        /*int count[256] = {0};
        for(auto &c : s){
            count[c]++;
        }
        sort( s.begin(), s.end(), [&count](char a, char b){
            return (count[a] > count[b]) || (count[a] == count[b] && a<b);
        });
        return s;*/
        
        vector< pair<char, int> > count(256);
        for(char c : s){
            count[c].first = c;
            count[c].second++;
        }
        sort( count.begin(), count.end(), 
             [&count](pair<char, int> &a, pair<char, int> &b){
                return (a.second > b.second);// || (a.second ==b.second  && a.first > b.first);
           });
        string ans;
        for( auto it = count.begin(); it!=count.end(); ++it){
            if( it->second == 0)
                continue;
            ans.append(string(it->second,it->first));
        }
        return ans;
    }
};