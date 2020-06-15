[432.all-oone-data-structure](https://leetcode.com/problems/all-oone-data-structure/)  

Implement a data structure supporting the following operations:

1.  Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a **non-empty** string.
2.  Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a **non-empty** string.
3.  GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string `""`.
4.  GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string `""`.

Challenge: Perform all these in O(1) time complexity.  



**Solution:**  

```cpp
class AllOne {
public:
    /** Initialize your data structure here. */
    int mx = 0;
    int mn = 0;
    map<int, unordered_set<string> > cnt;
    unordered_map<string, int> m;
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        int count = m[key]++;
        if(count > 0) {
            if(cnt[count].size() > 1)
                cnt[count].erase(key);
            else
                cnt.erase(count);
        }
        ++count;
        if(cnt.count(mn) == 0)
            mn = count;
        else
            mn = min(mn, count);
        cnt[count].insert(key);
        mx = max(mx, count);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m[key] == 0) return;
        int count = m[key]--;
        if(cnt[count].size() <= 1)
            cnt.erase(count);
        else
            cnt[count].erase(key);
        if(cnt.count(mx) == 0)
            mx -= 1;
        --count;
        if(count > 0)
            cnt[count].insert(key);
        else
            m.erase(key);
        mn = min(mn, count);
        if(mn == 0 && mx > 0) {
            cnt.erase(0);
            mn = cnt.size() ? cnt.begin()->first : 0;
            /*for(auto &it : cnt) 
                if(it.first > 0 || mn == 0)
                    mn = min(mn == 0 ? INT_MAX:mn, it.first);*/
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(cnt[mx].size() == 0) return "";
        return *cnt[mx].begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(cnt[mn].size() == 0) return "";
        return *cnt[mn].begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
```
      