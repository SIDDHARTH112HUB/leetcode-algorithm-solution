[1146.snapshot-array](https://leetcode.com/problems/snapshot-array/)  

Implement a SnapshotArray that supports the following interface:

*   `SnapshotArray(int length)` initializes an array-like data structure with the given length.  **Initially, each element equals 0**.
*   `void set(index, val)` sets the element at the given `index` to be equal to `val`.
*   `int snap()` takes a snapshot of the array and returns the `snap_id`: the total number of times we called `snap()` minus `1`.
*   `int get(index, snap_id)` returns the value at the given `index`, at the time we took the snapshot with the given `snap_id`

**Example 1:**

**Input:** \["SnapshotArray","set","snap","set","get"\]
\[\[3\],\[0,5\],\[\],\[0,6\],\[0,0\]\]
**Output:** \[null,null,0,null,5\]
**Explanation:** 
SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
snapshotArr.set(0,5);  // Set array\[0\] = 5
snapshotArr.snap();  // Take a snapshot, return snap\_id = 0
snapshotArr.set(0,6);
snapshotArr.get(0,0);  // Get the value of array\[0\] with snap\_id = 0, return 5

**Constraints:**

*   `1 <= length <= 50000`
*   At most `50000` calls will be made to `set`, `snap`, and `get`.
*   `0 <= index < length`
*   `0 <= snap_id <` (the total number of times we call `snap()`)
*   `0 <= val <= 10^9`  



**Solution:**  

```cpp
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
```
      