//Link: https://leetcode.com/problems/construct-quad-tree/ 
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
       /* for(int i = 0; i < grid.size(); ++i){
            int sum = 0;
            for(int j = 0; j < grid[0].size(); ++j) {
                int t = grid[i][j];
                grid[i][j] += sum + (i > 0 ? grid[i-1][j] : 0);
                sum += t;
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return h(grid, 0, 0, grid.size()-1, grid[0].size()-1);
    }
    
    Node *h(vector<vector<int>>& grid, int t, int l, int b, int r) {
        if(t > b || l > r) return NULL;
       // cout<<t<<" "<<l<<" "<<b<<" "<<r<<endl;
        int p = (b - t + 1) * (r-l+1);
        int sum = grid[b][r] + ((t > 0 && l > 0) ? grid[t-1][l-1] :0) - (t > 0 ? grid[t-1][r]: 0) - (l > 0 ? grid[b][l-1]: 0);
        bool isLeaf = true;
        for(int i = t; i <=b; ++i) {
            for(int j = l; j <=r; ++j) {
                if(grid[i][j]!= grid[b][r]){
                    isLeaf = false;
                    break;
                }
            }
            if(!isLeaf) break;
        }
        if(isLeaf == true) return new Node(grid[b][r], true, NULL, NULL, NULL, NULL);
        
        int ht = (b + t) / 2, hr = (l + r) / 2;
        auto node = new Node(0, false,
                             h(grid, t, l, ht, hr),
                             h(grid, t, hr+1, ht, r),
                             h(grid, ht+1, l, b, hr),
                             h(grid, ht+1, hr+1, b, r));
        return node;
    }
};