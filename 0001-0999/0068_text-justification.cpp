//Link: https://leetcode.com/problems/text-justification/ 
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int prev = 0, cur= 0, len=0,cnt =0;
        words.push_back("");
        for(int i = 0; i<words.size(); i++){
            len += words[i].size();
            if( len + cnt + words[i+1].size()+1 <= maxWidth &&  i+1 != words.size()){
                cnt++;
            }else{
                if( i+1 == words.size() ){
                    if( cnt == 0 )
                        break;
                    else
                        cnt--;
                }
                string res = "";
                int space_cnt = 0;
                int space_mod = 0;
                if( cnt > 0){
                    space_cnt = (maxWidth-len)/cnt;
                    space_mod = (maxWidth-len)%cnt;
                }else{
                    space_cnt = maxWidth-len;
                }
                if( i+1 == words.size() ){
                    if( len < maxWidth)
                        space_cnt = 1;
                    else
                        space_cnt = 0;
                    space_mod = 0;
                }
                for( int j = prev; j<=prev+cnt; j++){
                    res += words[j];
                    if( space_cnt > 0 && (cnt == 0 || j<prev+cnt))
                        res += string(space_cnt, ' ');
                    if( space_mod-- > 0 )
                        res += ' ';
                }
                if( i+1 == words.size() ){
                    if( res.size() < maxWidth ){
                        res += string(maxWidth-res.size(), ' ');
                    }
                }
                ans.push_back(res);
                prev = i+1;
                len = 0;
                cnt = 0;
            }
        }
        return ans;
    }
};