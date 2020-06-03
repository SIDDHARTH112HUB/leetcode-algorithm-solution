//Link: https://leetcode.com/problems/can-place-flowers/ 
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        for( int i = 0; i<l;i++){
            if( flowerbed[i] == 0 ){
                if( (i-1>= 0 && flowerbed[i-1] == 1) || ( (i + 1 <l && flowerbed[i+1] == 1)  )  ){
                    continue;
                }else{
                    n--;
                    if( n <= 0 ) return true;
                    flowerbed[i] = 1;
                    i++;
                }
            }
        }
        return n<=0;
    }
};