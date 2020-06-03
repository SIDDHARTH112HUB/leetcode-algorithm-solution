//Link: https://leetcode.com/problems/course-schedule-ii/ 
class Solution {
public:
    vector<int> ans;
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, unordered_set<int> > course;
        for( auto &p:prerequisites){
            course[p.first].insert(p.second);
        }
        for( int i = 0; i<numCourses; i++)
            if( !dfs(course, i) )
                return {};
        return ans;
    }
    unordered_set<int> visited;
    unordered_set<int> visiting;
    bool dfs(map<int, unordered_set<int> > &courses, int cur ){
        if( visited.find(cur) != visited.end() )
            return true;
        visiting.insert(cur);
        for(auto &pre_course:courses[cur]){
            if( visiting.find(pre_course) != visiting.end() || !dfs(courses, pre_course))
                return false;
        }
        visiting.erase(cur);
        visited.insert(cur);
        ans.push_back(cur);
        return true;
    }
};