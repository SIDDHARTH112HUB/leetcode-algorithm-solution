//Link: https://leetcode.com/problems/push-dominoes/ 
class Solution {
public:
    string pushDominoes(string dominoes) {
        int size = dominoes.size();
        map<int, char> d;
        //d[-1] = 'L';
        d[size] = 'R';
        for(int i = 0; i<size; i++){
            if( dominoes[i] != '.'){
                d[i] = dominoes[i];
            }
        }
        //cout<<"begin "<<endl;
        char prev = 'L'; 
        int prev_idx = -1;
        for( auto &it:d){
            char dir = it.second;
            int idx = it.first;
            /*if( idx == prev_idx ){
                continue;
            }*/
            //cout<<"prev "<<prev<<prev_idx<<" dir "<<dir<<idx<<endl;
            if( dir == 'L' && prev=='R'){
                for( int i = 1; i<=(idx-prev_idx-1)/2; i++){
                    dominoes[i+prev_idx] = 'R';
                    dominoes[idx-i] = 'L';
                }
            }
            else if( dir=='L' ){
                for( int i =idx-1; i>=0; i--){
                    if( dominoes[i] == '.')
                        dominoes[i] = 'L';
                    else
                        break;
                }
            }else if( prev=='R' ){
                //cout<<"prev == R "<< prev_idx+1 << " "<<size<<endl;
                for( int i =prev_idx+1; i<size; i++){
                    //cout<<dominoes[i]<<" i: "<<i<<" "<<size<<endl;
                    if( dominoes[i] == '.')
                        dominoes[i] = 'R';
                    else
                        break;
                }
            }
            prev = dir;
            prev_idx = idx;
            
        }
        return dominoes;
    }
};