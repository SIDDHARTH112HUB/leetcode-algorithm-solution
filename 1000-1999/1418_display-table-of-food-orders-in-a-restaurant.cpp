//Link: https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/ 
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foodItems;
        map<int, map<string, int> > foodmap;
        for(auto &o : orders) {
            foodItems.insert(o[2]);
            ++foodmap[stoi(o[1])][o[2]];
        }
        vector<vector<string> > ans = {{"Table"}};
        for(auto &it : foodItems) {
            ans.back().push_back(it);
        }
        for(auto it : foodmap) {
            int table = it.first;
            ans.push_back({to_string(table)});
            for(auto f : foodItems) {
                ans.back().push_back(to_string(foodmap[table][f]));
            }
        }
        return ans;
    }
};