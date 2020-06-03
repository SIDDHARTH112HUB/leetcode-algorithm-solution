//Link: https://leetcode.com/problems/design-hashset/ 
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector< vector< int > > container= vector< vector< int > >(10000);
    MyHashSet() {
        
    }
    
    vector<int> &_get(int key){
        return container[key%container.size()];
    }
    
    void add(int key) {
        auto &vec = _get(key);
        for( auto k: vec){
            if( k == key)
                return;
        }
        vec.push_back(key);
    }
    
    void remove(int key) {
        auto &vec = _get(key);
        for( auto it=vec.begin(); it!=vec.end(); ++it){
            if( key == *it){
                vec.erase(it);
                return ;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto &vec = _get(key);
        for( auto k: vec){
            if( k == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */