//Link: https://leetcode.com/problems/parallel-courses/ 
class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) {
        unordered_map<int, unordered_set<int> > m;
        unordered_map<int, unordered_set<int> > prev;
        for(auto &r : relations) {
            m[r[0]].insert(r[1]);
            prev[r[1]].insert(r[0]);
        }
        queue<int> q;
        unordered_set<int> v;
        int res = 0;
        for(int i = 1; i <= N; ++i){
            if(m[i].size() == 0){
                q.push(i);
                v.insert(i);
            }
        }
        while(q.size()) {
            int size = q.size();
            while(size-- > 0) {
                int c = q.front();
                q.pop();
                v.insert(c);
                for(auto n : prev[c]) {
                    m[n].erase(c);
                    if(m[n].size() == 0)
                        q.push(n);
                }
            }
            ++res;
        }
        return v.size()== N ? res: -1;
    }
};