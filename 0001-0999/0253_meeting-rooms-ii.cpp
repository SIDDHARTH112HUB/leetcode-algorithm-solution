//Link: https://leetcode.com/problems/meeting-rooms-ii/ 
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for(auto &inter : intervals) {
            ++m[inter[0]];
            --m[inter[1]];
        }
        int cnt = 0, ans = 0;
        for(auto it : m) {
            cnt += it.second;
            ans = max(cnt, ans);
        }
        return ans;
    }
};