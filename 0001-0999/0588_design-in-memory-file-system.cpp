//Link: https://leetcode.com/problems/design-in-memory-file-system/ 
struct File {
    unordered_map<string, File*> files;
    bool isFile = false;
    string content;
    string fileName;
    void build(string path, bool isFile = false, string content = "") {
        auto file = getFile(path);
        file->isFile = isFile;
        if(isFile) {
            file->content += content;
        }
    }
    
    File* getFile(string path) {
        stringstream ss(path);
        string token;
        auto file = this;
        // cout<<"path:"<<path<<endl;
        while(getline(ss, token, '/')) {
            // cout<<" file:"<<token<<endl;
            if(!file->files[token]) file->files[token] = new File();
            file = file->files[token];
        }
        file->fileName = token;
        return file;
    }
    
    vector<string> ls(string path) {
        auto file = getFile(path);
        vector<string> ans;
        if(file->isFile) {
            // cout<<fileName<<endl;
            return {file->fileName};
        }
        for(auto &it : file->files)
            ans.push_back(it.first);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class FileSystem {
public:
    File *file;
    FileSystem() {
        
        file = new File();
        file->build("/");
    }
    
    vector<string> ls(string path) {
        return file->ls(path);
    }
    
    void mkdir(string path) {
        file->build(path);
    }
    
    void addContentToFile(string filePath, string content) {
        file->build(filePath, true, content);
    }
    
    string readContentFromFile(string filePath) {
        auto f = file->getFile(filePath);
        return f->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */