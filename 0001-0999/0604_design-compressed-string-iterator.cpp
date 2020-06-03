//Link: https://leetcode.com/problems/design-compressed-string-iterator/ 
class StringIterator {
public:
    string s;
    int idx = 0;
    int cnt = 0;
    char ch = 0;
    StringIterator(string compressedString) {
        s = compressedString;
    }
    
    char next() {
        if(!hasNext()) return ' ';
        if(cnt == 0) {
            ch = s[idx++];
            while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9')
                cnt = cnt * 10 + s[idx++] - '0';
        }
        --cnt;
        return ch;
    }
    
    bool hasNext() {
        if(cnt == 0 && idx >= s.size()) return false;
        return true;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */