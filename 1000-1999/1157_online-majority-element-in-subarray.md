[1157.online-majority-element-in-subarray](https://leetcode.com/problems/online-majority-element-in-subarray/)  

Implementing the class `MajorityChecker`, which has the following API:

*   `MajorityChecker(int[] arr)` constructs an instance of MajorityChecker with the given array `arr`;
*   `int query(int left, int right, int threshold)` has arguments such that:
    *   `0 <= left <= right < arr.length` representing a subarray of `arr`;
    *   `2 * threshold > right - left + 1`, ie. the threshold is always a strict majority of the length of the subarray

Each `query(...)` returns the element in `arr[left], arr[left+1], ..., arr[right]` that occurs at least `threshold` times, or `-1` if no such element exists.

**Example:**

  
MajorityChecker majorityChecker = new MajorityChecker(\[1,1,2,2,1,1\]);
  
majorityChecker.query(0,5,4); // returns 1
  
majorityChecker.query(0,3,3); // returns -1
  
majorityChecker.query(2,3,2); // returns 2
  

**Constraints:**

*   `1 <= arr.length <= 20000`
*   `1 <= arr[i] <= 20000`
*   For each query, `0 <= left <= right < len(arr)`
*   For each query, `2 * threshold > right - left + 1`
*   The number of queries is at most `10000`  



**Solution:**  

```cpp


class MajorityChecker {
public:
    map<int, unordered_map<int, vector<int> > > freq;
    MajorityChecker(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int n : arr)
            ++m[n];
        for(int i = 0; i < arr.size(); ++i){
            int n = arr[i];
            freq[m[n]][n].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        int res = -1;
        auto it = freq.lower_bound(threshold);
        while(it != freq.end()){
            for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
                int num = it2->first;
                auto &vec = it2->second;
                if(upper_bound(vec.begin(), vec.end(), right) - lower_bound(vec.begin(), vec.end(), left) >= threshold)
                    return num;
            }
            ++it;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
```
      