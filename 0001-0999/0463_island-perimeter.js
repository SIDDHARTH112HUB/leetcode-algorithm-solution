//Link: https://leetcode.com/problems/island-perimeter/ 
/**
 * @param {number[][]} grid
 * @return {number}
 */
var islandPerimeter = function(grid) {
    var sum = 0;
    for( var i = 0; i<grid.length;i++){
        for( var j = 0;j<grid[i].length; j++){
            
            if( grid[i][j] > 0 ){
                var s = 4;
                if( grid[i][j-1] == 1 )
                    s--;
                if( (grid[i-1]||[])[j] == 1 )
                    s--;
                if( (grid[i+1]||[])[j] == 1 )
                    s--;
                if( grid[i][j+1] == 1 )
                    s--;
                sum += s;
            }
            
        }
    }
    return sum;
};