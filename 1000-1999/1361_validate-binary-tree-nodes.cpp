//Link: https://leetcode.com/problems/validate-binary-tree-nodes/ 
class Solution {
public:
    map<int, set<int> > m;
    map<int, int> p;
    set<int> v;
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0; i < leftChild.size(); ++i) {
            if(leftChild[i] == rightChild[i] && leftChild[i] >= 0)
                return false;
            if(leftChild[i] >= 0) {
                m[i].insert(leftChild[i]);
                p[leftChild[i]] = i;
            }
            if(rightChild[i] >= 0) {
                m[i].insert(rightChild[i]);
                p[rightChild[i]] = i;
            }
        }
        int root = -1;
        for(int i = 0; i < n; ++i) {
            if(p.count(i) == 0) {
                if(root != -1 ) return false;
                root = i;
            }
        }
        if(!dfs(root)) return false;
        return v.size() == n;
    }
    
    bool dfs(int root) {
        if(v.count(root)) return false;
        v.insert(root);
        for(auto next : m[root]) {
            if(!dfs(next)) return false;
        }
        return true;
    }
};