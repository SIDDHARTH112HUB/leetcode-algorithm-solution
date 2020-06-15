//Link: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/ 

class TreeAncestor {
public:
    int f[50002][20];   
    TreeAncestor(int m, vector<int>& parent) {
        memset(f, 0, sizeof(f));
        for(int i = 0; i < parent.size(); ++i) {
            f[i][0] = parent[i];
        }
        for(int k = 1; k < 20; ++k) {
            for(int i = 0; i < parent.size(); ++i) {
                int j = f[i][k-1];
                f[i][k] = j < 0 ? -1 : f[j][k-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; ++i) {
            if(((1 << i) & k)) node = f[node][i];
            if(node == -1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */