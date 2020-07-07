[1500.design-a-file-sharing-system](https://leetcode.com/problems/design-a-file-sharing-system/)  

  



**Solution:**  

```cpp
class FileSharing {
public:
    int userID = 0;
    unordered_map<int, set<int> > ownerChunks;
    unordered_map<int, set<int> > ChunksOwners;
    set<int> idPool;
    FileSharing(int m) {
        
    }
    
    int join(vector<int> ownedChunks) {
        int id = 0;
        if(idPool.size()) {
            id = *idPool.begin();
            idPool.erase(id);
        }else {
            id = ++userID;
        }
        for(auto n : ownedChunks) {
            ownerChunks[id].insert(n);
            ChunksOwners[n].insert(id);
        }
        return id;
    }
    
    void leave(int userID) {
        auto &chunks = ownerChunks[userID];
        for(auto n : chunks) {
            ChunksOwners[n].erase(userID);
        }
        idPool.insert(userID);
        ownerChunks.erase(userID);
    }
    
    vector<int> request(int userID, int chunkID) {
        if(ChunksOwners[chunkID].size() == 0) {
            return {};
        }
        auto &data = ChunksOwners[chunkID];
        vector<int> ans(data.begin(), data.end());
        ChunksOwners[chunkID].insert(userID);
        ownerChunks[userID].insert(chunkID);
        return ans;
    }
};

/**
 * Your FileSharing object will be instantiated and called as such:
 * FileSharing* obj = new FileSharing(m);
 * int param_1 = obj->join(ownedChunks);
 * obj->leave(userID);
 * vector<int> param_3 = obj->request(userID,chunkID);
 */
```
      