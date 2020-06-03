//Link: https://leetcode.com/problems/similar-rgb-color/ 
class Solution {
public:
    string similarRGB(string color) {
        map<char, int> map_color;
        for( int i = 0; i<10; i++){
            map_color[i+'0'] = i;
            map_color[i] = i+'0';
        }
        for( int i = 10; i<16; i++){
            map_color[i+'a'-10] = i;
            map_color[i] = i+'a'-10;
        }
        int AB = map_color[color[1]] *16 + map_color[color[2]];
        int CD = map_color[color[3]] *16 + map_color[color[4]];
        int EF = map_color[color[5]] *16 + map_color[color[6]];
        //printf(" AB:%d, CD:%d, EF:%d \n", AB, CD ,EF);
        char ans[8];
        ans[7] = 0;
        ans[0] = '#';
        int min_num = 100000;
        for( int i = 0; i<16; i++){
            for( int j = 0; j<16; j++){
                for( int k = 0; k<16; k++){
                    int num = -(AB-i*16-i ) * (AB-i*16-i ) - (CD-j*16-j)* (CD-j*16-j) - (EF-k*16-k)*(EF-k*16-k);
                    if( abs(num) < abs(min_num)){
                        min_num = num;
                        ans[1] = map_color[i];
                        ans[2] = map_color[i];
                        ans[3] = map_color[j];
                        ans[4] = map_color[j];
                        ans[5] = map_color[k];
                        ans[6] = map_color[k];
                       // printf("i %d j %d k%d num %d \n", i, j, k, num);
                    }
                }
            }
        }
        return ans;
    }
};