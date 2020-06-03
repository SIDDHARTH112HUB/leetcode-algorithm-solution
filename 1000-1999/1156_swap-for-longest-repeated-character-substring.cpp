//Link: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/ 
class Solution {
public:
    int maxRepOpt1(string text) {
        /*cout<<f("babababa",'a')<<endl;
        cout<<f("aabba",'a')<<endl;
        cout<<f("aabaaa",'a')<<endl;
        cout<<f("aabbaaba",'a')<<endl;
        cout<<f("bbaabaaba",'a')<<endl;
        cout<<f("bbaabaaba",'a')<<endl;
        cout<<f("aaaa",'a')<<endl;*/
        text.push_back(' ');
        int ans = 0;
        for(char c = 'a'; c <= 'z'; ++c)
            ans = max(ans, f(text, c));
        return ans;
    }
    
    int f(string &text, char c) {
        int last = 0;
        int total = 0;
        int first = INT_MAX;
        for(int i = 0; i < text.size(); ++i){
            if(text[i] == c) {
                ++total;
                if(first == INT_MAX)
                    first = i;
            }
        }
        if(total == 0) return 0;
        int prev = first;
        int ans = 0;
        int mid = 0;
        int i = first+1;
        bool change = false;
        for(i = first+1; i < text.size(); ++i){
            if(text[i] == c) {
                if(prev == -1)
                    prev = i;
            }else{
                
                int j = i;
                while(j < text.size() && text[j] != c){
                    ++j;
                }
                
                if(j == text.size()){
                    ans = max(ans, i - prev + 1);
                    break;
                }
                
                while(text[i+1] == c)
                    ++i;
                ans = max(ans, i - prev + 1);
                prev = j;
                /*
                if( change == false){
                    mid = i;
                    change = true;
                    if(total > i - prev + 1)
                        ans = max(ans, i - prev + 1);
                    else
                        return total;
                }
                else{
                    ans = max(ans, i - prev);
                    change = false;
                    prev = -1;
                }*/
            }
        }
        return min(total, max(ans, i - prev));
    }
};