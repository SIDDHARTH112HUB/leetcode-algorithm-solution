//Link: https://leetcode.com/problems/repeated-dna-sequences/ 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if( s.size() <= 10 ) return {};
        int num = 0;
        map<int, int> dict;
        map<char, int> dna;
        dna['A'] = 0;
        dna['C'] = 1;
        dna['G'] = 2;
        dna['T'] = 3;
        
        dna[0] = 'A';
        dna[1] = 'C';
        dna[2] = 'G';
        dna[3] = 'T';
        
        for( int i = 0; i<s.size(); i++){
            num = num<<2;
            num = (num| dna[s[i]]) & 0x000FFFFF;
            if( i>=9 )
                dict[num]++;
            
        }
        vector<string> ans;
        for(auto it:dict){
            if( it.second > 1){
                string str;
                int cnt = 10;
                int num = it.first;
                while(cnt-->0){
                    str += dna[num & 3];
                    num = num>>2;
                }
                reverse(str.begin(), str.end());
                ans.push_back(str);
            }
        }
        return ans;
    }
};