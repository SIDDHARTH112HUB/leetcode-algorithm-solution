//Link: https://leetcode.com/problems/lfu-cache/ 
class LFUCache {
    int minFreq, cap;
    unordered_map<int, list<int> > freq; // frequency: list< key > 
    unordered_map<int, list<int>::iterator> iter;  // key : iterator
    unordered_map<int, pair<int, int> > m;          //key : {value, frequency }
public:
    LFUCache(int capacity) {
        minFreq = 1;
        if( capacity <= 0 )
            capacity = 0;
        cap = capacity;
    }
    
    int get(int key) {
        auto mit = m.find(key);
        if( mit == m.end() ) return -1;
        auto it = iter.find(key);
        int curFreq = mit->second.second;
        freq[curFreq+1].push_back(key);
        freq[curFreq].erase(it->second);
        iter[key] = --freq[curFreq+1].end();
        mit->second.second++;
        if( freq[minFreq].size() == 0 )
            ++minFreq;
        return mit->second.first;
    }
    
    void put(int key, int value) {
        
        if( this->cap == 0 )
            return;
        
        if( get(key) == -1){
            m[key] = {value, 1};
            if( m.size() > this->cap){
                m.erase(freq[minFreq].front());
                iter.erase(freq[minFreq].front());
                freq[minFreq].pop_front();
            }
            freq[1].push_back(key);
            iter[key] = --freq[1].end();
            minFreq = 1;
        }else{
            m[key].first = value;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */