//Link: https://leetcode.com/problems/meeting-scheduler/ 
class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int j = 0,i = 0;
        while(i < slots1.size() && j < slots2.size()){
            if(slots1[i][0] > slots2[j][1]) {
                ++j;
                continue;
            }
            if(slots2[j][0] > slots1[i][1]){
                ++i;
                continue;
            }
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            if(end - start >= duration){
                return {start, start + duration};
            }
            if(slots1[i][1] > slots2[j][1])
                ++j;
            else
                ++i;
        }
        return {};
        /*
        int s1c=0, s2c = 0;
        int last = 0;
        map<int, int> m;
        for(auto &s : slots1) {
            m[s[0]] = 1;
            m[s[1]] = -1;
        }
        for(auto &s : slots2) {
            m[s[0]] = 2;
            m[s[1]] = -2;
        }
        int cnt = 0;
        for(auto it1 : m) {
            int t = it1.first;
            int v = it1.second;
            if(v < 0 && s1c >0 && s2c > 0) {
                if(duration <= t - last) {
                    return {last, duration};
                }
            }
            if(v == 1) {
                if(s1c == 0)
                    last = t;
                ++s1c;
            }
            else if(v == 2){
                if(s2c == 0)
                    last = t;
                ++s2c;
            }
            else if(v == -1) 
                --s1c;
            else if(v == -2)
                --s2c;
            
        }
        return {};*/
    }
};