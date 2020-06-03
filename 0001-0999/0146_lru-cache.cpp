//Link: https://leetcode.com/problems/lru-cache/ 
class LRUCache {
public:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if( it == m.end() ) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if( it != m.end() ) l.erase(it->second);
        l.push_front({key, value});
        m[key] = l.begin();
        if( l.size() > this->capacity ){
            m.erase(l.back().first);
            l.pop_back();
        }
        /*
        if( it == m.end() ){
            l.push_front({key, value});
            m[key] = l.begin();
            if(l.size() > this->capacity ){
                m.erase(l.back().first);
                l.pop_back();
            }
        }else{
            l.splice(l.begin(), l, it->second);
            it->second->second = value;
        }*/
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */