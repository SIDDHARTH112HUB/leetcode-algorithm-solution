//Link: https://leetcode.com/problems/iterator-for-combination/ 
class CombinationIterator {
public:
    string str;
    vector<int> pos;
    CombinationIterator(string characters, int combinationLength) {
        str = characters;
        pos.resize(combinationLength);
        for(int i = 0; i < pos.size(); ++i)
            pos[i] = i;
    }
    
    int helper(int i) {
        if(i == -1) return str.size();
        if(pos[i] + (pos.size() - i) >= str.size() ) 
            return pos[i] = helper(i-1) + 1;
        else
            return pos[i] += 1;
    }
    string next() {
        string s;
        for(auto p : pos)
            s += str[p];
        helper(pos.size()-1);
        return s;
    }
    
    bool hasNext() {
        return pos[0] < str.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */