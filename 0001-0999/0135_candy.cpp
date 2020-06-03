//Link: https://leetcode.com/problems/candy/ 
class Solution {
public:
    int candy(vector<int>& ratings) {
        if( ratings.size() == 0 ) return 0;
        vector<int> candy(ratings.size(), 1 );
        for( int i = 1; i<ratings.size(); i++){
            if( ratings[i] > ratings[i-1])
                candy[i] = candy[i-1]+1;
        }
        for( int i = ratings.size()-1; i>0; i--){
            if( ratings[i] < ratings[i-1])
                candy[i-1] = max(candy[i-1], candy[i]+1);
        }
        return accumulate(candy.begin(), candy.end(), 0);
        /*
        vector<int> candy(ratings.size(),1);
        for(int i = 1; i < candy.size() ; i++ ){
            if( ratings[i] > ratings[i-1])
                candy[i] = candy[i-1]+1;
        }
        for( int i = candy.size()-1; i>0; i--){
            if( ratings[i] < ratings[i-1]){
                candy[i-1] = max(candy[i]+1, candy[i-1]);
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);*/
    }
};