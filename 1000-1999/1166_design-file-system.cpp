//Link: https://leetcode.com/problems/design-file-system/ 
class FileSystem {
public:
    unordered_map<string, int> m;
    FileSystem() {
        
    }
    
    bool create(string path, int value) {
        if(m.count(path)) return false;
        for(int i = path.size() - 1; i >= 0; --i) {
            if(path[i] == '/') {
                string tmp = path.substr(0, i);
                if(i > 0 && m.count(tmp) == 0) return false;
                m[path] = value;
                return true;
            }
        }
        return false;
    }
    
    int get(string path) {
        if(m.count(path)) return m[path];
        return -1;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */