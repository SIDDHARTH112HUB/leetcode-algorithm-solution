[609.find-duplicate-file-in-system](https://leetcode.com/problems/find-duplicate-file-in-system/)  

Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least **two** files that have exactly the same content.

A single directory info string in the **input** list has the following format:

`"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"`

It means there are **n** files (`f1.txt`, `f2.txt` ... `fn.txt` with content `f1_content`, `f2_content` ... `fn_content`, respectively) in directory `root/d1/d2/.../dm`. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The **output** is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

`"directory_path/file_name.txt"`

**Example 1:**

  
**Input:**
  
\["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"\]
  
**Output:**  
  
\[\["root/a/2.txt","root/c/d/4.txt","root/4.txt"\],\["root/a/1.txt","root/c/3.txt"\]\]
  

**Note:**

1.  No order is required for the final output.
2.  You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of \[1,50\].
3.  The number of files given is in the range of \[1,20000\].
4.  You may assume no files or directories share the same name in the same directory.
5.  You may assume each given directory info represents a unique directory. Directory path and file info are separated by a single blank space.

**Follow-up beyond contest:**

1.  Imagine you are given a real file system, how will you search files? DFS or BFS?
2.  If the file content is very large (GB level), how will you modify your solution?
3.  If you can only read the file by 1kb each time, how will you modify your solution?
4.  What is the time complexity of your modified solution? What is the most time-consuming part and memory consuming part of it? How to optimize?
5.  How to make sure the duplicated files you find are not false positive?  



**Solution:**  

```cpp
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> > m;
        vector<vector<string> > ans;
        
        for( auto &path : paths ){
            string cur_path, filename;
            int file_name_begin = 0, content_begin=0;
            for( int i = 0; i < path.size(); i++ ){
                char c = path[i];
                if( c == ' '){
                    if( cur_path == "" ){
                        cur_path = path.substr(0, i);
                    }
                    file_name_begin = i+1;
                    continue;
                }
                else if( c == '('){
                    filename = path.substr(file_name_begin, i-file_name_begin);
                    content_begin = i+1;
                }
                else if( c == ')'){
                    
                    string content = path.substr(content_begin, i-content_begin);
                    m[content].push_back(cur_path+"/"+filename);
                }
            }
        }
        for( auto &it: m){
            if( it.second.size() > 1 )
                ans.push_back(it.second);
        }
        return ans;
    }
};
```
      