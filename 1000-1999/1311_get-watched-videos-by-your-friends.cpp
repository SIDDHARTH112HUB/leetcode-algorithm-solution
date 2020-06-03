//Link: https://leetcode.com/problems/get-watched-videos-by-your-friends/ 
class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> f;
        queue<int> q;
        q.push(id);
        set<int> v;
        v.insert(id);
        while(q.size() && level > 0) {
            int size = q.size();
            while(size-- > 0) {
                int curid = q.front(); q.pop();
                for(auto fri : friends[curid]) {
                    if(v.count(fri) == 0) {
                        q.push(fri);
                        if(level == 1)
                            f.push_back(fri);
                    }
                    v.insert(fri);
                }
            }
            --level;
        }
        map<string, int> m;
        vector<pair<int, string> > pm;
        for(auto fri : f) {
            for(auto &vedio : watchedVideos[fri]) {
                ++m[vedio];
            }
        }
        for(auto it : m) {
            pm.push_back({it.second, it.first});
        }
        sort(pm.begin(), pm.end(), [](auto &a, auto &b){
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });
        vector<string> ans;
        for(auto &p : pm) {
            ans.push_back(p.second);
        }
        return ans;
    }
};