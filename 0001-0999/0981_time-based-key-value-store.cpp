//Link: https://leetcode.com/problems/time-based-key-value-store/ 
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string> > m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto &m2 = m[key];
        auto it = m2.upper_bound(timestamp);
        if(it == m2.begin()) return "";
        --it;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */