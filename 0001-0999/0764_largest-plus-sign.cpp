//Link: https://leetcode.com/problems/largest-plus-sign/ 
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mine) {
        //vector<int> v = vector<int>(N, 1);
        vector< vector<int> > mines(N, vector<int>(N, 1));
        for( auto &m : mine){
            mines[m[0]][m[1]] = 0;
        }
        if( N == 1 ){
            if( mines[0][0] == 1) return 1;
            return 0;
        }
        if( N== 2){
            if( mines[0][0] == 1 ) return 1;
            if( mines[0][1] == 1 ) return 1;
            if( mines[1][0] == 1 ) return 1;
            if( mines[1][1] == 1 ) return 1;
            return 0;
        }
        
        int X = mines.size();
        int Y = mines[0].size();
        int maxOrder = 1;
        int order = 0;
       // printf("1 \n");
        for( int n = 1; n<=N/2;n++){
            for( int col = n; col<N-n; col++){
                order = checkMine(mines, N, N , n, col);
                if( order > maxOrder)
                    maxOrder = order;
                if( order == n+1 )
                    break;
             //   printf("2 \n");
                order = checkMine(mines, N, N , N-n-1, col);
                
                if( order > maxOrder)
                    maxOrder = order;
                if( order == n+1)
                    break;
                
                order = checkMine(mines, N, N , col, n);
                if( order > maxOrder)
                    maxOrder = order;
                if( order == n+1 )
                    break;
                
                order = checkMine(mines, N, N ,  col, N-n-1);
                
                if( order > maxOrder)
                    maxOrder = order;
                if( order == n+1)
                    break;
            }
          //  printf("3 \n");
            
        }
        return maxOrder;
    }
    int checkMine(vector< vector<int> > &mines, int X, int Y, int x, int y){
        int order = 1;
        //printf("5 %d %d %d \n", x, y, mines[x][y]);
        if( mines[x][y] != 1) return 0;
        //printf("4 \n");
        for( int i = 1; i<500;i++){
            if( x-i<0 || y-i<0 || x+i >=X || y+i >=Y)
                break;
            if( mines[x-i][y]==1 && mines[x+i][y]==1 && mines[x][y-i]==1 && mines[x][y+i]==1 )
                order = i+1;
            else
                break;
          //  printf("6 \n");
        }
        return order;
    }
};