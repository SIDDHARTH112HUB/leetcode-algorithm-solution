//Link: https://leetcode.com/problems/flood-fill/ 
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        stack<pair<int, int> > stk;
        stk.push({sr,sc});
        int maxRow = image.size();
        int maxCol = image[0].size();
        int realNewCol = newColor;
        newColor = -1;
        while(!stk.empty()){
            auto item = stk.top();
            stk.pop();
            image[item.first][item.second] = newColor;
            if( item.first - 1 >=0 ){
                if( image[item.first - 1 ][item.second] == oldColor ){
                    image[item.first-1][item.second] = newColor;
                    stk.push({item.first-1, item.second});
                }
            }
            if( item.first + 1 < maxRow ){
                if( image[item.first + 1 ][item.second] == oldColor ){
                    image[item.first+1][item.second] = newColor;
                    stk.push({item.first+1, item.second});
                }
            }
            if( item.second + 1 < maxCol ){
                if( image[item.first ][item.second+1] == oldColor ){
                    image[item.first][item.second + 1] = newColor;
                    stk.push({item.first, item.second+1});
                }
            }
            if( item.second - 1 >=0 ){
                if( image[item.first ][item.second-1] == oldColor ){
                    image[item.first][item.second - 1] = newColor;
                    stk.push({item.first, item.second-1});
                }
            }
        }
        for( auto &item: image){
            for(auto &i : item){
                if( i == - 1)
                    i = realNewCol;
            }
        }
        return image;
    }
};