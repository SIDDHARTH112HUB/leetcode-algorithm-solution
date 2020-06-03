//Link: https://leetcode.com/problems/synonymous-sentences/ 
class Solution {
public:
    map<string, string> uf;
    map<string, set<string> > m;
    vector<string> ans;
    string find(string &str) {
        if(uf.count(str)) return uf[str] = (uf[str] == str ? str : find(uf[str]));
        return uf[str] = str;
    }
    void combine(string &a, string &b) {
        auto h1 = find(a);
        auto h2 = find(b);
        if(h1 != h2) 
            uf[h2] = h1;
        uf[h1] = a;
        uf[a] = a;
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        stringstream ss(text);
        vector<string> arr;
        set<string> allwords;
        string token;
        while(getline(ss, token, ' ')) {
            arr.push_back(token);
            allwords.insert(token);
        }
        for(auto &syns : synonyms) {
            allwords.insert(syns[0]);
            for(int i = 1; i < syns.size(); ++i) {
                combine(syns[i], syns[0]);
                allwords.insert(syns[i]);
            }
        }
        for(auto str : allwords) {
            m[find(str)].insert(str);
        }
        vector<string> item;
        h(arr, 0, item);
        return ans;
    }
    
    void h(vector<string> &arr, int idx, vector<string> &item) {
        if(idx >= arr.size()) {
            string str;
            for(auto &s : item){ str += s; str += ' ';}
            str.pop_back();
            ans.push_back(str);
            return;
        }
        for(auto &str: m[find(arr[idx])]) {
            item.push_back(str);
            h(arr, idx+1, item);
            item.pop_back();
        }
    }
};