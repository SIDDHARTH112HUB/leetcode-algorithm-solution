//Link: https://leetcode.com/problems/longest-consecutive-sequence/ 
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> s(num.begin(), num.end());
        int ans = 0;
        for(int low : s ){
            if( s.find(low-1) == s.end()){
                int hight = low+1;
                while( s.find(hight) != s.end() ){
                    hight++;
                }
                ans = max(ans, hight - low);
            }
        }
        return ans;
    }
    /*
    int longestConsecutive(vector<int> &num) {
        map<int, int> hm;
        for(int i = 0; i < num.size(); i++)
        {
            hm[num[i]] = i;
        }
        int seq_num = 0,max=0;
        for(int i = 0; i < num.size(); i++)
        {
            int v = num[i];
            int vs = v;
            seq_num = 0;
            do
            {
                map<int, int>::iterator iter = hm.find(v);
                if( iter == hm.end())
                    break;
                
                hm.erase(iter);
                
                ++seq_num;
                ++v;
            }while(true);
            --vs;
            do
            {
                map<int, int>::iterator iter = hm.find(vs);
                if( iter == hm.end())
                    break;
                hm.erase(iter);
                ++seq_num;
                --vs;
            }while(true);
            
            if( seq_num > max )
                max=seq_num;
        }
        return max;
    }*/
};