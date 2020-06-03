//Link: https://leetcode.com/problems/alien-dictionary/ 
class Solution {
public:
    map<char, set<int> > g;
    map<char, set<int> > degree;
    string ans;
    set<int> v;
    set<int> v2;
    string alienOrder(vector<string>& words) {
        // cout<<"begin"<<endl;
        if(words.size() == 1) return words[0];
        set<int> ch;
        for(int i = 1; i < words.size(); ++i) {
            auto word = words[i], pword = words[i-1];
            for(auto c : word) degree[c];
            for(auto c : pword)degree[c];
            if(word.size() < pword.size() && pword.substr(0, word.size()) == word) {
                return "";
            }
            for(int j = 0; j < min(word.size(), pword.size()); ++j) {
                
                if(pword[j] == word[j]) {
                    continue;
                }
                degree[word[j]].insert(pword[j]);
                g[pword[j]].insert(word[j]);
                break;
            }
        }
        queue<int> q;
        int size = degree.size();
        for(auto it : degree) {
            // cout<<it.first<<" "<<it.second.size()<<endl;
            if(it.second.size() == 0) {
                q.push(it.first);
            }
        }
        while(q.size()) {
            int size = q.size();
            while(size--) {
                int p = q.front(); q.pop();
                degree.erase(p);
                ans.push_back(p);
                for(auto n : g[p]) {
                    if(degree[n].size() == 0) return "";
                    degree[n].erase(p);
                }
            }
            for(auto it : degree) {
                if(it.second.size() == 0) {
                    q.push(it.first);
                }
            }
        }
        return ans.size() == size ? ans : "";
    }
    
    bool dfs(int node) {
        if(v.count(node)) return false;
        v.insert(node);
        for(auto next: g[node]) {
            if(!dfs(next)) return false;
        }
        v.erase(node);
        if(v2.count(node) == 0)
            ans.push_back(node);
        v2.insert(node);
        return true;
    }
};