//Link: https://leetcode.com/problems/course-schedule/ 
class Solution {
public:
    map<int, set<int> > g;
    map<int, int> d;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto &p : prerequisites) {
            g[p[0]].insert(p[1]);
            ++d[p[0]];
        }
        for(int i = 0; i < numCourses; ++i) {
            set<int> v;
            if(!h(i, v))return false;
        }
        return true;
    }
    set<int> global_visit;
    bool h(int root, set<int> &v) {
        if(v.count(root)) return false;
        if(global_visit.count(root)) return true;
        v.insert(root);
        global_visit.insert(root);
        for(auto next : g[root]) {
            if(!h(next, v))return false;
        }
        v.erase(root);
        return true;
    }
};