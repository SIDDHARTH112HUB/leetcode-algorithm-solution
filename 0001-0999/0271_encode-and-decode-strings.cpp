//Link: https://leetcode.com/problems/encode-and-decode-strings/ 
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string ans;
        for(auto &str:strs) {
            string size = to_string(str.size());
            ans += to_string(size.size()) + size;
            ans += str;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0;
        vector<string> ans;
        while(i < s.size()) {
            string t = s.substr(i + 1, s[i] - '0');
            int size = stoi(t);
            i += s[i] - '0' + 1;
            ans.push_back(s.substr(i, size));
            i += size;
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));