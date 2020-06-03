//Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/ 
class Solution {
public:
    map<int, map<int, int> > m;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //cout<<"begin"<<endl;
        for(int i = 0; i < manager.size(); ++i) {
            int head = manager[i];
            m[head][i] = informTime[i];
        }
        return h(-1);
    }
    
    int h(int head) {
        int res = 0;
        for(auto &it : m[head]) {
            int sub = it.first;
            int time = it.second;
            //cout<<sub<<" time: "<<it.second<<endl;
            res = max(res, h(sub) + time);
        }
        return res;
    }
};