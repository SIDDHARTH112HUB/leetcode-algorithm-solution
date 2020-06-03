//Link: https://leetcode.com/problems/snapshot-array/ 
class SnapshotArray {
public:
    unordered_map<int, map<int, int> > arr;
    int id = 0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        arr[index][id] = val;
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        if(arr.size() == 0)
            return 0;
        if(arr.find(index) == arr.end()) return 0;
        auto it = arr[index].lower_bound(snap_id);
        if(it == arr[index].begin() && it->first != snap_id)
            return 0;
        if(it == arr[index].end() || it->first != snap_id)
            --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */