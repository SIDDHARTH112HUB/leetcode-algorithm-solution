[588.design-in-memory-file-system](https://leetcode.com/problems/design-in-memory-file-system/)  

Design an in-memory file system to simulate the following functions:

`ls`: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names **in this directory**. Your output (file and directory names together) should in **lexicographic order**.

`mkdir`: Given a **directory path** that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.

`addContentToFile`: Given a **file path** and **file content** in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to **append** given content to original content. This function has void return type.

`readContentFromFile`: Given a **file path**, return its **content** in string format.

**Example:**

  
**Input:** 
  
\["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"\]
  
\[\[\],\["/"\],\["/a/b/c"\],\["/a/b/c/d","hello"\],\["/"\],\["/a/b/c/d"\]\]
  

  
**Output:**
  
\[null,\[\],null,null,\["a"\],"hello"\]
  

  
**Explanation:**
  
![filesystem](https://assets.leetcode.com/uploads/2018/10/12/filesystem.png)
  

**Note:**

1.  You can assume all file or directory paths are absolute paths which begin with `/` and do not end with `/` except that the path is just `"/"`.
2.  You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
3.  You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.  



**Solution:**  

```cpp
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
```
      