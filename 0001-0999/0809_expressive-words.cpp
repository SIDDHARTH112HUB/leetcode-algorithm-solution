//Link: https://leetcode.com/problems/expressive-words/ 
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ans = 0;
        for( auto &word:words){
            int i = 0, j=0;
            bool flag = true;
            for( ; i<word.length() && j<S.length();){
                int cnt  = 0;
                if( word[i] == S[j] ){
                    char c = word[i];
                    int c1 = 0, c2=0;
                    while(word[++i] == c)
                        c1++;
                    while(S[++j] == c)
                        c2++;
                    if( c1 != c2 && c2 < 2 ){
                        flag = false;
                        break;
                    }
                    continue;
                }else{
                    flag = false;
                    break;
                }
            }
            if( i == word.length() && j == S.length() && flag == true )
                ans++;
        }
        return ans;
    }
};