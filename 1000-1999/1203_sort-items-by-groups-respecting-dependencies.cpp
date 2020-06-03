//Link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/ 
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        unordered_map<int, int> groupInDegree, itemInDegree;
        unordered_map<int, set<int> > groupGraph, itemGroup;
        int maxGroup = m;
        for(int i = 0; i < n; ++i) {
            if(group[i] == -1) {
                group[i] = maxGroup++;
            }
        }
        for(int i = 0; i < beforeItems.size(); ++i) {
            auto &items = beforeItems[i];
            auto g = group[i];
            for(auto item: items){
                if(g != group[item] && groupGraph[g].count(group[item]) == 0){
                    ++groupInDegree[group[item]];
                
                    groupGraph[g].insert(group[item]);
                }
                ++itemInDegree[item];
                itemGroup[i].insert(item);
            }
        }
        queue<int> q;
        int cnt = 0;
        for(int i = 0; i < maxGroup; ++i) {
            if(groupInDegree[i] == 0){
                //cout<<"groupInDegree:"<<i<<" "<<groupInDegree[i]<<endl;
                q.push(i);
            }
        }
        vector<int> groupOrder;
        while(q.size()) {
            int g = q.front();
            q.pop();
            ++cnt;
            groupOrder.push_back(g);
            for(auto next : groupGraph[g]) {
                if(--groupInDegree[next] == 0){
                    q.push(next);
                }
            }
        }
        if(cnt != maxGroup) {
            //cout<<"no max group "<<cnt<<" "<<groupOrder.size()<<endl;
            return {};
        }
        q = {};
        for(int i = 0; i < n; ++i) {
            if(itemInDegree[i] == 0)
                q.push(i);
        }
        vector<vector<int>> grouparr(maxGroup);
        while(q.size()) {
            int item = q.front();
            q.pop();
            grouparr[group[item]].push_back(item);
            for(auto next : itemGroup[item]) {
                if(--itemInDegree[next] == 0)
                    q.push(next);
            }
        }
        vector<int> ans;
        for(auto g : groupOrder)
            for(auto n : grouparr[g])
                ans.push_back(n);
        if(ans.size() != n) {
            return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};