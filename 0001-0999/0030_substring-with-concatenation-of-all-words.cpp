//Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/ 
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if( words.size() == 0 || s.size()== 0) return {};
        map<string, int> wordset;
        for(string &w:words)
            wordset[w]++;
        map<string, int> dict;
        int wlen = words[0].size();
        int cnt = 0;
        
        
        int begin = 0, end=0;
        vector<int> ans;
        
        while(end<s.size()){
            string word = s.substr(end, wlen);
            //cout<<word<<endl;
            if(cnt == words.size() || wordset.find(word) == wordset.end() || dict[word] >= wordset[word] ){
                //cout<<"not found "<<word<<endl;
                if( cnt == words.size() )
                    ans.push_back(begin);
                begin +=1;
                end = begin;
                cnt = 0;
                if( dict.size() > 0)
                    dict = map<string, int>();
                continue;
            }
            dict[word]++;
            cnt++;
            if( cnt != words.size() ){
                end+=wlen;
            }
        }
        return ans;
    }
};