//Link: https://leetcode.com/problems/letter-tile-possibilities/ 
class Solution {
public:
    unordered_set<string> ans;
    int numTilePossibilities(string tiles) {
        string item;
        dfs(tiles, 0, item);
        return ans.size();
        
    }
    void dfs(string &tiles, int idx, string &item) {
        if(item.size() > tiles.size())
            return;
        //item.push_back(tiles)
        if(item.size() && ans.count(item) == 0)
            ans.insert(item);
        if(item.size() == tiles.size())
            return;
        for(int i = 0; i < tiles.size(); i++){
            if( tiles[i] == '.') continue;
            item.push_back(tiles[i]);
            char src = tiles[i];
            tiles[i] = '.';
            dfs(tiles, i+1, item);
            item.pop_back();
            tiles[i] = src;
        }
    }
};