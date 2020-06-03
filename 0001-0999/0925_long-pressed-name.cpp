//Link: https://leetcode.com/problems/long-pressed-name/ 
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int j = 0;
        for( int i = 0; i< typed.size(); i++ ){
            
            if( typed[i] == name[j] ){
                j++;
                if( j == name.size() )
                    return true;
            }else{
                if(i > 0 && typed[i] == typed[i-1])continue;
                return false;
            }
            
        }
        return false;
    }
    
};