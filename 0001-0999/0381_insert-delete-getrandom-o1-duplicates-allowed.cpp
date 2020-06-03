//Link: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/ 
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    unordered_map<int, unordered_set<int> > m;
    vector<int> arr;
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        arr.push_back(val);
        m[val].insert(arr.size()-1);
        return m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m[val].size() == 0) return false;
        int idx = *m[val].begin();
        m[val].erase(idx);
        if(idx != arr.size() -1 ){
            int num = arr.back();
            m[num].erase(arr.size()-1);
            m[num].insert(idx);
            arr[idx] = num;
        }
        arr.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        if(arr.size() == 0) return -1;
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */