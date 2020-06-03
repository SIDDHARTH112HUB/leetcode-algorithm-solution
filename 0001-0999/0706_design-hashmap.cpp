//Link: https://leetcode.com/problems/design-hashmap/ 
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector< vector<pair<int, int> > > container= vector< vector<pair<int, int> > >(10000);
    MyHashMap() {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        for( auto &p:container[key%container.size()]){
            if( p.first == key){
                p.second = value;
                return;
            }
        }
        container[key%container.size()].push_back({key,value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for( auto &p:container[key%container.size()]){
            if( p.first == key){
                return p.second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &vec = container[key%container.size()];
        for( auto it = vec.begin(); it!= vec.end(); ++it){
            if( it->first == key){
                vec.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */