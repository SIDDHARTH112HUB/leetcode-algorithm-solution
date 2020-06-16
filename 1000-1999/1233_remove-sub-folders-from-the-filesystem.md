[1233.remove-sub-folders-from-the-filesystem](https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/)  

Given a list of folders, remove all sub-folders in those folders and return in **any order** the folders after removing.

If a `folder[i]` is located within another `folder[j]`, it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: `/` followed by one or more lowercase English letters. For example, `/leetcode` and `/leetcode/problems` are valid paths while an empty string and `/` are not.

**Example 1:**

  
**Input:** folder = \["/a","/a/b","/c/d","/c/d/e","/c/f"\]  
**Output:** \["/a","/c/d","/c/f"\]  
**Explanation:** Folders "/a/b/" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.  

**Example 2:**

  
**Input:** folder = \["/a","/a/b/c","/a/b/d"\]  
**Output:** \["/a"\]  
**Explanation:** Folders "/a/b/c" and "/a/b/d/" will be removed because they are subfolders of "/a".  

**Example 3:**

  
**Input:** folder = \["/a/b/c","/a/b/ca","/a/b/d"\]  
**Output:** \["/a/b/c","/a/b/ca","/a/b/d"\]  

**Constraints:**

*   `1 <= folder.length <= 4 * 10^4`
*   `2 <= folder[i].length <= 100`
*   `folder[i]` contains only lowercase letters and '/'
*   `folder[i]` always starts with character '/'
*   Each folder name is unique.  



**Solution:**  

```cpp
struct Trie{
    unordered_map<string, Trie*> nodes;
    bool isWord = false;
    void build(string &word) {
        auto node = this;
        for(int i = 1; i < word.size(); ++i) {
            string str;
            while(i < word.size() && word[i] != '/')
                str += word[i++];
            //cout<<str<<endl;
            auto next = node->nodes[str];
            if(!next) next = new Trie();
            node->nodes[str] = next;
            node = next;
        }
        node->isWord = true;
    }
};

class Solution {
public:
    vector<string> ans;
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie t;
        for(auto &f : folder)
            t.build(f);
        string fol = "/";
        dfs(&t, fol);
        return ans;
    }
    
    void dfs(Trie *t, string &folder) {
        //folder += '/';
        if(t->isWord ==true) {
            folder.pop_back();
            ans.push_back(folder);
            folder += '/';
            return;
        }
        for(auto &it : t->nodes){
            auto c = it.first;
            auto next = it.second;
            folder += c;
            folder += '/';
            dfs(next, folder);
            folder.pop_back();
            while(folder.size() && folder.back() !='/') folder.pop_back();
        }
        //folder.pop_back();
    }
};
```
      